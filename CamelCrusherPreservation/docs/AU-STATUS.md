# CamelCrusher Preservation AU 0.2.0

Native AUv2 music effect using the recovered CamelCrusher DSP and original bitmap interface. Universal bundle: ARM64 and x86_64. Separate identity: aumf / CrP1 / Prsv.

## Completed adapter behavior

- All 17 normalized parameters retain the recovered order, including the five unused stored slots.
- All 20 original factory presets appear in the host and custom editor.
- Project state preserves the full edited 20-program bank, selected legacy program and host user-preset name.
- Original-style raw single-program chunks and investigated big-endian 17-float state arrays are accepted by the adapter.
- Cocoa editor, FXP import, module controls and randomization are integrated. Randomization uses the same modern convenience RNG as the preservation VST adapters; it does not reproduce the original RNG stream.

## Verification and limits

Apple Silicon Mac CI builds both architectures, checks ad hoc code signatures, runs Apple's auval, and runs a direct AU host/editor test. That test compares 240 cases / 829,440 channel samples with the recovered core at 44.1/48/96 kHz and blocks 31/64/257/512, across all factory presets and parameter changes. It requires maximum sample error zero. It also checks edited-bank recall, host custom-name recall, unused parameters, legacy state decoding, malformed-state rejection and the editor's eight original images.

AU-to-core equality validates the adapter, not full equality with the original hosted AU. Previous selected original-binary DSP evidence still applies. Full original-AU comparison renders and actual Live/FL AU testing remain pending.

The original wrapper's quiet-counter optimization and MIDI Learn are not implemented. Scheduled automation is adapted at host-block granularity. The AU declares a conservative new 30-second tail, which is integration metadata, not a recovered original constant.

The default new component coexists with the original AU and does not automatically replace old AU instances. The source-only CAMEL_AU_LEGACY_ID option collides with the original identity and is not certified for original-AU project recall. Existing VST2/VST3 0.1.1 binaries are unchanged.

## Build AU only

Requires a recent Xcode/libc++ with C++23 support (CI uses Xcode 16.4), and CMake 3.25+.

```bash
git clone https://github.com/apple/AudioUnitSDK.git deps/AudioUnitSDK
git -C deps/AudioUnitSDK checkout bd98b31feff57a15989fcfab4cd86dc63382b1ac
cmake -S . -B build-au -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0 -DCAMEL_BUILD_VST3=OFF -DCAMEL_BUILD_AU=ON -DAUDIOUNIT_SDK_ROOT="$PWD/deps/AudioUnitSDK"
cmake --build build-au --parallel
ctest --test-dir build-au --output-on-failure -V
```

The deployment target is macOS 11; runtime tests are on the stated CI image, not every older OS. The AU smoke test loads/registers its bundle in-process, so it can test the actual factory/editor without changing installed plugins. Normal OS registration/auval is checked separately by CI on its disposable runner.

Installation: AU-INSTALL.md. Distribution/provenance limits: ../NOTICE.md. The release bundles Apple's AudioUnitSDK license.
