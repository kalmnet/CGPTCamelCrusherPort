# CamelCrusher 1.01 preservation research

C++ reconstruction from the **supplied Intel VST and AU binaries**, with a native macOS ARM64 VST3 build target, original bitmap GUI assets, a legacy ABI compatibility adapter, and an experimental AUv2 target. No replacement `tanh` distortion, substitute compressor, Moog-style filter, or added oversampling was used.

**Status:** compiled universal macOS VST3 and legacy VST2 test bundles are now available. They include ARM64 and x86_64 slices, passed architecture/signature checks, core/adapter tests and 47 VST3 validator tests on an Apple Silicon GitHub runner (Xcode 15.4). [Download](https://github.com/kalmnet/CGPTCamelCrusherPort/actions/runs/37819328990/artifacts/11567644736) and follow [installation steps](docs/INSTALL.md). Cocoa code compiled, but GUI appearance, full original-AU renders and old Ableton Live/FL Studio project recall remain unverified. The experimental AU target is not included in the binary package.

Your observation is recorded in the report: the existing AU responds to parameters despite a black GUI; the existing VST has a black GUI and its parameters do not audibly work. Use the AU as the full-plugin reference on your Mac.

Read [verified findings](docs/FINDINGS.md), [project migration](docs/MIGRATION.md), [testing](docs/TESTING.md), and [licensing/provenance](NOTICE.md). `docs/evidence/` contains hashes, selected decompilation, differential-test results and validator output. `docs/factory-presets.json` lists the exact original float32 values.

## Build the native ARM64 VST3

Install Xcode/Command Line Tools and CMake 3.25 or later. Build dependencies are external and pinned; the SDK is not included in the source archive.

```bash
git clone https://github.com/steinbergmedia/vst3sdk.git deps/vst3sdk
git -C deps/vst3sdk checkout 3cdf9ca5d1f5b1b21e0a86832aa4abe55607bd96
git -C deps/vst3sdk submodule update --init --recursive
export VST3_SDK_ROOT="$PWD/deps/vst3sdk"
bash tools/build_macos.sh
```

The default build produces `build-macos/VST3/Release/CamelCrusherPreservation.vst3`. The script requests `arm64`, runs the core checks and SDK validator, checks the architecture, and applies an ad hoc signature. It does not install or replace plugins. If the Cocoa source does not compile with your Xcode version, retain the error log: that is an uncompleted validation gate, not an already-tested Mac build.

After a successful build, copy the VST3 bundle to `~/Library/Audio/Plug-Ins/VST3/`, rescan the DAW, and test a new empty project first. VST3 has its own identity and **does not automatically replace the old VST2 instance** in Live or FL Studio.

## Optional legacy adapter for old VST2 projects

The independently declared ABI adapter exports the old plugin name and `CaCr` ID, with 17 parameters and 20 programs. It uses the reconstructed DSP, not the broken original VST wrapper. It includes no VST2 SDK source. Read `NOTICE.md` before choosing to use or distribute it.

```bash
CAMEL_BUILD_LEGACY=ON bash tools/build_macos.sh
```

Find the resulting `CamelCrusher.vst` bundle under `build-macos/`. Keep a backup of the original VST bundle and old projects. Install the new legacy bundle only after following `docs/MIGRATION.md`. Do not register both VST2 implementations with the same ID in a DAW scan. The adapter's Cocoa editor uses the legacy NSView extension and needs a real Live/FL Studio test; its generic host parameter editor is an additional test path.

## Optional AUv2 source target

The AU target uses Apple's Apache-2.0 AudioUnitSDK. The pinned version uses C++23 and requires a sufficiently recent Xcode/libc++.

```bash
git clone https://github.com/apple/AudioUnitSDK.git deps/AudioUnitSDK
git -C deps/AudioUnitSDK checkout bd98b31feff57a15989fcfab4cd86dc63382b1ac
export AUDIOUNIT_SDK_ROOT="$PWD/deps/AudioUnitSDK"
CAMEL_BUILD_AU=ON bash tools/build_macos.sh
```

Its default component identity is `aumf / CrP1 / Prsv`, so it can coexist with the functioning original AU. It has the same reconstructed DSP and a Cocoa editor. This is experimental, uncompiled here, and must pass `auval` and render comparisons before use. `CAMEL_AU_LEGACY_ID=ON` changes the identity to the recovered `aumf / CaCr / CamA`; that collides with the original AU and is a separate recall experiment, not the default.

## Import existing settings

The converter supports the supplied Camel FXB quirk, ordinary chunk FXP/FXB files, parameter FXP files, raw Camel chunks, and the investigated AU plist data encodings.

```bash
python3 tools/presets.py old-bank.fxb --json settings.json
python3 tools/presets.py old-bank.fxb --program 13 --vstpreset Dream.vstpreset
python3 tools/presets.py old-preset.fxp --vstpreset Imported.vstpreset
```

Load the `.vstpreset` into the new VST3 using your host's preset loader. If your host cannot import VST3 preset files, the custom editor can import a single FXP, or use the legacy adapter to load the original chunks. A raw bank does not encode its selected program: choose `--program` explicitly. `resources/FactoryBank.vstpreset` contains the recovered factory bank with program zero selected.

## Build and test without macOS or a plugin SDK

```bash
cmake -S . -B build-core -DCMAKE_BUILD_TYPE=Release -DCAMEL_BUILD_VST3=OFF
cmake --build build-core --parallel
ctest --test-dir build-core --output-on-failure
python3 tests/test_presets.py
```

`camel_render` renders interleaved little-endian stereo float32 through the recovered core. The original DSP oracle and the macOS Rosetta AU reference host are described in `docs/TESTING.md`.

## Deliberate limits

- The Windows DLL was not supplied. Cross-platform state encoding is investigated; Windows DSP equivalence and actual project replacement are not established.
- VST3 parameter queues are collapsed to the last value per host block to feed the legacy block engine. Dense sample-offset automation may differ from how an old DAW split VST2 blocks.
- Original wrapper silence/quiet-counter bypass is not reproduced; full-plugin tail comparisons remain pending.
- MIDI Learn, the original MIDI event scheduler, circular knob interaction, and the full original preset/file menus are not implemented.
- GUI randomization uses a modern RNG. The distortion/filter/compressor signal algorithms do not use that substitute.
- The background, control sprites and main readout glyphs are original. Cocoa interaction code compiled on macOS; version text uses an AppKit font. Visual and interaction validation in real DAWs remains pending.
- The AU host tail declaration and AU adapter state handling are new integration behavior and require their own validation.
