# Verified findings and unresolved behavior

“Verified” below means evidence from the supplied bytes, raw instructions, or the limited executable DSP experiments described here. It does not mean a native ARM64 host test has taken place.

## Supplied material

The ZIP has VST and AU bundles, the factory bank, an older copy of that bank, external PNG skins, a MIDI map, and a version-1.0 manual. Both executable files are universal Mach-O bundles with x86-64, i386, and PowerPC slices. The VST bundle metadata says 1.01 and has a 2006 build date. The AU metadata also says 1.01 and its copyright string says 2011. Metadata is not a proof that the two wrapper builds are identical.

| Intel slice | SHA-256 |
| --- | --- |
| VST | `ef7529f06f4f9ee05d914a4b59a21b63c651dfe362fc80dafa4e73ddab63f557` |
| AU | `834860ca5d4c59576dde1619d4e17050489ade3b0f756827ee4a7c56f3d322b0` |

`evidence/inventory.json` includes the archive hash, per-file hashes, slice offsets/sizes, and plist contents. The symbols are retained, so the primary path was disassembly and decompilation of Intel code, not a model chosen from the manual's descriptions. PowerPC and i386 were inventoried, but not independently reconstructed.

The attached manual's license and prose were treated as source material, not instructions overriding the user's request.

## Legacy identity and stored parameters

The VST constructor writes unique ID `0x43614372` (`CaCr`). There are 17 stored/host parameters and 20 VST programs. The larger internal parameter collection also contains UI-only commands; those must not be mistaken for serialized audio parameters.

| Legacy index | Name | Stored normalized range | Processing interpretation |
| --- | --- | --- | --- |
| 0 | DistOn | 0–1 | Module active when smoothed value > 0.5 |
| 1 | DistMech | 0–1 | Mech amount; gain `1 + 10p` |
| 2 | DistTube | 0–1 | Tube amount; gain `1 + 4p` |
| 3 | MmFilterOn | 0–1 | Filter active when smoothed value > 0.5 |
| 4 | MmFilterCutoff | 0–1 | Logarithmic map to 80–16000 Hz |
| 5 | MmFilterRes | 0–1 | Biquad Q `1 + 6p` |
| 6 | CompressOn | 0–1 | Compressor active when smoothed value > 0.5 |
| 7 | CompressAmount | 0–1 | Internally mapped to 0–0.99; display approximately 0–40 dB |
| 8 | CompressMode | 0–1 | Below 0.5 enables the envelope follower; Phat >= 0.5 uses instantaneous peak |
| 9 | MasterOn | 0–1 | Below 0.5 bypasses the engine at wrapper level |
| 10 | MasterMix | 0–1 | Linear wet/dry mix, then output gain |
| 11 | MasterVolume | 0–1 | Output gain `p^2.736999988555908` |
| 12–16 | Unused1–Unused5 | 0–1 | Retained in serialized state and host indexing |

The “clear preset” values are all zero except cutoff = 0.5, master on = 1, master mix = 1, master volume = 1. Loading the factory bank selects program zero, Annihilate, which has different settings. `factory-presets.json` contains every exact float32 value and name. The manual's statement about 64 patches does not describe the 20-program binary/bank supplied here.

The original custom range-check function is empty. The new adapters/parser validate finite normalized values and reject malformed/out-of-range state; that is defensive integration behavior, not evidence of an original clamp. Valid original presets are preserved exactly.

## Recovered DSP

The VST Intel address column refers to virtual addresses inside the extracted thin x86-64 image, not offsets into the ZIP or universal file.

| Routine | VST address | Verified role |
| --- | --- | --- |
| CamelCrusher::process | `0x39c0` | Mech → filter → Tube → compressor → mix/gain → output clamp; 64-frame internal blocks |
| Distortion::processMech stereo | `0x32c60` | Piecewise linear saturation |
| Distortion::processTube stereo | `0x32db0` | Polynomial knee; no tanh |
| CACompressor::process | `0x31140` | Stereo-linked soft limiting with linear gain recovery |
| EnvelopeFollower::process | `0x2dd50` | Linear rise/fall follower |
| MMFilter::process | `0x4d4d0` | Selects mode zero, processes coefficient updates in 16-frame groups, then linked limiter |
| CAFilterBiquad::makeLowPassFilter | `0x4f480` | Double-precision trigonometric coefficient calculation, stored float coefficients |
| CAFilterBiquad::process | `0x50530` | Direct-form float history recurrence |
| PParam::advanceTimeGetParam | `0x7420` | Linear normalized smoothing advancement |
| PParam::setParam | `0x6760` | Stores destination and resets the smoothing ramp |

### Mech

For amount `p`, let `g = 1 + 10p`, `y = gx`, and `k = 0.25/(g - 0.75)`. The output is `y` inside ±0.75. Above the knee it is `0.75 + (y - 0.75)k`, and the negative side is mirrored. This is not a hard clip.

### Tube

Let `g = 1 + 4p`, `y = gx`. The signal is unchanged inside ±`0.6000000238418579`. On either outer side, the code computes a scaled polynomial term using `0.7071070075035095` and `0.7999999523162842`, and mirrors the negative side. The exact ordered float operations are in `src/Dsp.cpp`.

The curve is deliberately not clamped to a conventional saturation shape before the master's output clamp. Inputs above unity can fold back: for example, input 2 with amount 0.5 produces approximately 0.374999613 in the original routine. Replacing this with tanh would alter the sound.

### Filter

The active table entry selects an ordinary low-pass CAFilterBiquad pair with **one-times processing**, despite its table label “LP2 Fat” and the presence of many other unused filter classes in the binary.

The normalized frequency map is:

```
t = -0.25 * log10(1 - p)
frequency = 80 + 15920 * t
```

with the original endpoint/threshold branches bounding the map at 80 and 16000 Hz. Frequency is converted through float MIDI-note/log/power operations before coefficient generation. This apparently redundant round trip was retained because removing it changes rounding.

The low-pass coefficient calculation uses `Q = 1 + 6p`, double sine/cosine, then float coefficients and float direct-form history. Cutoff moves in 16-frame groups inside each 64-frame engine block. The filter wrapper also has a stereo-linked envelope limiter: follower attack 0.0075 s, release 0.05 s, and a 7.5 s linear gain-recovery denominator. Filter internal wet mix starts at -1 after rate reset and ramps to one; its startup behavior was preserved rather than “corrected.”

### Compressor

The amount is internally capped at float 0.99. The scale is `1/(1 - previousAmount)`, computed once per internal block. The knee is float 0.31; its polynomial uses float 0.7071070075 and 1.38. Detection uses the greater absolute channel value, so the two channels share gain.

Phat mode uses the instantaneous peak. Turning Phat off enables a follower with 0.03 s attack and 0.08 s release. The recovery target uses the preceding release value, and the routine stores 0.00025 s for the next block. Gain recovery is linear and can overshoot one; the original branches and operation order were retained. The amount field advances per sample but the block scale remains fixed until the next call.

### Master and smoothing

The master linearly combines dry and wet, multiplies by `volume^2.736999988555908`, and clamps the final processed output to approximately ±0.9998999834. Master bypass at the wrapper level returns the unprocessed input, without that clamp.

PParam smoothing duration is `int(sampleRate * 0.01f)` frames. Distortion parameters are advanced for the whole host block during activation checks and advanced again inside active 64-frame blocks. The resulting timing is unusual and was reproduced. Disabled stages can retain dormant smoothing/filter history.

Resume resets parameter ramps and compressor history, but does not reset the master gain/mix or filter history in the same way as constructing a new instance. The port keeps that distinction. No oversampling, DC blocker, substitute filter, new transfer curve or new audio limiter was added.

## Preset and state formats

The supplied FXB starts with `CcnK`, kind `FBCh`, ID `CaCr`, and 20 programs. The payload starts at byte 160. Its 32-bit outer `byteSize` is **1927, the entire file size**, whereas conventional FXB encodes file size minus eight. The importer accepts both forms specifically while requiring the correct plugin ID and bounded size/counts.

Inside the chunk, each program is:

```
float32 little-endian presetVersion
NUL-terminated name
uint32 little-endian parameterCount
parameterCount float32 little-endian normalized values
```

The factory version is 1.0 and parameterCount is 17. `FileIO::readFloat/writeFloat/readInt/writeInt` explicitly assemble little-endian bytes. This is evidence for cross-platform state portability, rather than relying on the native endianness of the Intel host. The parser does not remove unused slots. The factory chunk round-trips byte-for-byte.

A raw bank is 20 concatenated program records. It does not itself encode a selected program. The old host supplies the selection separately; the raw-bank converter requires an explicit index. Reserved bytes in the supplied outer bank header must not be interpreted as a valid current index.

The new VST3 component state adds `CCP1` plus a little-endian current-program index before a full 20-program legacy bank. This is a **new state envelope**, while the enclosed values remain the old normalized values. The converter emits a conventional VST3 preset with a `Comp` chunk for the new processor class ID.

The old AU resource identifies `aumf / CaCr / CamA`. The AU wrapper's state methods use a plist `data` key. Disassembly/decompilation identifies a chunk-state branch using the VST preset chunk and a non-chunk branch using byte-swapped float parameter arrays. The converter supports these investigated encodings, but full original-AU `.aupreset` restore behavior has not been dynamically tested on macOS.

The original bank's data conversion from a different `CaP3` product is present in CamelCrusherProgram::loadCustom. It was investigated but is not implemented as a supported import path: this work targets CamelCrusher's `CaCr` state. Parameter-only FXB banks are also not supported by the current importer; parameter FXP is supported.

## GUI evidence

The actual assets were extracted before writing UI code: background 345×373, knobs 48×2640 (55 frames), on/off buttons 32×48, Phat 22×40, random button 93×56 and selector 196×90. `SkinParameters.txt` supplies control positions. The new editor uses those original pixels and centers rather than redrawing a generic interface. The main bitmap font's file says 75 characters, but its supplied character/width lists contain 74 entries, totaling the bitmap's 414 pixels; the editor uses those actual entries.

The old files refer to an external CamelCrusherData skin directory. The new build packages skin PNGs inside each bundle. This removes that external lookup dependency; it does not prove the cause of the black GUI reported on the user's Mac.

## Executable evidence and its limits

The exact supplied x86-64 DSP code was memory-mapped on Linux, with selected vtable pointers relocated and only the required math/memory imports bound. The harness reconstructs the relevant objects and calls the original DSP methods. It does **not** load the entire plugin, call GUI code, run global initializers, or test AU/VST host dispatch. Only the two known binary hashes are accepted.

For each binary: 2,880 comparisons, 1,102,080 channel samples, all 20 factory presets, sample rates 22050/44100/48000/88200/96000/192000, block lengths 1/8/16/31/63/64/65/127/128/257/512/1024, and parameter changes on eight controls. Maximum absolute sample error was **0**, with no non-finite outputs. Input was reproducible independent stereo random data between -1.5 and 1.5. These results do not cover every possible input/state.

Ghidra sometimes generated bad instruction boundaries and implausible decompilation, particularly in the AU wrapper and some PParam functions. Those dumps are not presented as truth; raw objdump instructions and the executable DSP comparison resolved the audio-relevant paths. AU wrapper state methods remain less strongly verified than the DSP.

## Approximations and unverified areas

| Area | Status |
| --- | --- |
| Active Mech, Tube, biquad/filter limiter and compressor algorithms | Recovered, tested against both original Intel DSP images in the stated harness |
| Normalized parameter order, factory values, little-endian chunks | Recovered and round-trip tested |
| Windows binary DSP and host metadata | Not supplied; not verified |
| Native macOS ARM64 compilation, libm rounding and DAW scanning | Source/build target provided; not executed here |
| Reopening real Ableton Live/FL Studio projects | Adapter and import routes provided; requires actual projects/host tests |
| VST2 NSView extension on those hosts | Implemented, not tested in those hosts |
| VST3 dense automation offsets | New block-boundary queue adaptation; possible differences |
| Original wrapper quiet-counter/silence bypass | Identified in wrapper decompilation; not implemented or dynamically verified; long silence/tails may differ |
| MIDI Learn and original MIDI event timing | Not implemented; supplied default map has all entries unassigned (-1) |
| Randomize | Original targets/distributions investigated; modern RNG integration, not original RNG stream; AU convenience behavior also differs |
| GUI interaction | New Cocoa event handling, linear drag and Shift fine adjustment; circular mode/context menus not fully replicated |
| Version text and original display timing | AppKit version font and 3-second UI timer; not pixel/timing verified |
| AU wrapper | Experimental source, new default ID, new preset/tail integration; macOS compilation and auval pending |
| `CaP3` conversion and parameter-only FXB | Investigated or identified, unsupported import paths |

## User-reported macOS behavior

The user reports: AU opens with a black GUI but its parameters change the sound; VST opens with a black GUI and parameter changes have no audible effect. This is a user observation, not a reproduced finding in this environment. It changes the testing plan: use the original AU under Rosetta as the full-host sound/parameter reference, while retaining VST binary analysis for its shared DSP and Windows-compatible legacy state format.
