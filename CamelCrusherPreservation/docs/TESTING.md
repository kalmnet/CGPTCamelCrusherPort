# Testing and acceptance gates

## Checks completed in this environment

Linux x86-64, GCC 14, Release: reconstructed core and legacy adapter tests; five Python preset tests; Steinberg VST3 validator (47 passed, zero failed); selected original Intel DSP differential comparisons for both supplied images. Evidence logs are in evidence/. These checks do not validate AppKit, macOS ARM64, Rosetta full-plugin processing, Live/FL recall or Windows binaries.

## Repeat the portable checks

Follow README.md to build. With the optional legacy target enabled, CTest also loads the adapter and checks `CaCr`, parameter/program counts, exact chunk round-trip, selection, generic parameter writes and rendering against the core.

```bash
ctest --test-dir build-core --output-on-failure
python3 tests/test_presets.py
```

Malformed state tests exercise truncation, count bounds and preserving existing state when decode fails. Factory FXB import checks the supplied nonstandard outer byteSize and every recovered program value.

## Repeat the original Intel DSP experiment

This deliberately executes selected original machine-code routines, not the original plugin's full entry point. Use an isolated Linux x86-64 environment and the exact user-supplied archive. The loader rejects unknown binary hashes. numpy is required.

```bash
python3 tools/inventory.py /path/to/CamelCrusher.zip work/recovered
python3 tools/differential.py --binary work/recovered/vst-x86_64.macho --bridge build-core/libcamel_test_bridge.so --execute-original --report work/vst-results.json
python3 tools/differential.py --binary work/recovered/au-x86_64.macho --bridge build-core/libcamel_test_bridge.so --execute-original --report work/au-results.json
```

Each comparison starts reconstructed objects with a factory preset and runs deterministic stereo data over six sample rates, twelve block sizes and a second pass with parameter changes. Recorded results: zero maximum sample error, 2,880 cases and 1,102,080 channel samples per binary. Linux libm is bound to the selected math imports. This proves the stated paths under those conditions; it does not establish universal bit equality or macOS math equality.

## Full original AU reference on your Rosetta Mac

Use an isolated test copy of the working original AU. Install only the original `aumf / CaCr / CamA` reference for these runs. The reference executable uses AudioComponent discovery and generic parameters, so its GUI is not involved.

```bash
mkdir -p work/reference
clang++ -std=c++17 -arch x86_64 tools/au_reference.cpp -framework AudioToolbox -framework CoreFoundation -o work/reference/au_reference_intel
python3 tools/render_tests.py fixtures work/reference/fixtures --rate 48000
python3 tools/presets.py tests/fixtures/factory-bank.fxb --program 13 --parameters work/reference/params.f32 --raw work/reference/preset.chunk
arch -x86_64 work/reference/au_reference_intel work/reference/fixtures/sweep.f32 work/reference/original.f32 48000 512 work/reference/params.f32 aumf CaCr CamA
build-macos/camel_render work/reference/fixtures/sweep.f32 work/reference/core.f32 48000 512 work/reference/preset.chunk 13
python3 tools/render_tests.py compare work/reference/original.f32 work/reference/core.f32
```

The AU host sets 17 parameters before initialization and verifies their readbacks. Keep its output `.params.f32` with the render. A setup mismatch, original AU refusing initialization, or parameter readback failure must be resolved before treating the render as a DSP comparison. The documented commands are provided for Mac execution, not reported as already run.

Render all six fixture signals, all 20 presets, rates 44100/48000/96000, blocks 1/16/31/64/127/512/1024 and sustained silence after filter/compressor excitation. Extend to longer renders and parameter changes in the DAW. Use identical initialization, block size and pre-roll; smoothing/startup makes those part of the experiment. Compare peak and RMS residual, investigate every systematic difference, and retain the raw renders. Do not silently align, normalize or discard startup samples to claim equality.

After building the experimental new AU, use the ARM64 reference executable with `aumf CrP1 Prsv` and the same fixture/settings. Compare original-AU vs new-AU as well as original-AU vs core. Separately render the VST3 through the DAW with the same setup. This isolates core/math differences from adapter/host differences.

## Native plugin and editor checks

The build script requests ARM64 and checks VST3 architecture, signature and SDK validator. Verify legacy/AU architectures and sign those bundles separately when testing them. Run `auval -v aumf CrP1 Prsv` for the default new AU; run the original identity only when it is the intended sole registered component. Confirm actual component discovery, not just bundle existence.

In both Live and FL Studio, test scan/load/unload, multiple instances, preset selection, every knob/button, Shift fine adjustment, resizing rejection, open/close/reopen editor, FXP import, automation recording/playback, suspend/resume, sample-rate changes, variable blocks, bypass, project save/reopen and offline export. Check that the original 345×373 artwork appears rather than a black panel. Measure CPU, unexpected allocations on the audio thread and long-run stability. The macOS sources remain uncompiled here; these are required acceptance gates.

## Old-project acceptance

Follow MIGRATION.md. A recall pass requires matching all saved normalized values and current program, intact automation mapping, audible parameter response and a repeatable render after closing/reopening the project. Include one Windows-origin and one old Mac project in each relevant DAW. Capture DAW/version/platform and plugin format. Plugin ID or successful preset import alone is not a recall pass.

## Known gaps to target

Dense sample-offset VST3 automation, MIDI Learn/events, wrapper silence optimization, full AU state restore, original GUI interactions, extreme valid parameter transitions and filter tails require additional tests. The original wrapper contains an endpoint-based quiet counter and a conditional bypass path; it is outside the selected-DSP oracle and not reproduced in the new adapters. Full-plugin silence/tail renders must establish its audible impact before claiming complete behavior preservation.
