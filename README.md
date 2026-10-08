# CamelCrusher Mac test plugins

**Compiled Mac plugins are now available. No coding or Xcode is needed to install them.**

[Download the Mac plugin ZIP](https://github.com/kalmnet/CGPTCamelCrusherPort/actions/runs/37824633602/artifacts/11570837505) while signed in to GitHub. Extract the downloaded ZIP and the plugin ZIP inside it.

Version 0.1.1 corrects the legacy VST2 Cocoa editor attachment and negotiation; its Mac editor smoke test verifies attachment and all eight bundled images. Live/FL visual retesting remains necessary.

Read [the installation steps](CamelCrusherPreservation/docs/INSTALL.md). The download contains `CamelCrusherPreservation.vst3` and the optional old-project compatibility adapter `CamelCrusher.vst`. Both include native ARM64 and Intel x86_64 code.

The macOS build succeeded on an Apple Silicon runner using Xcode 15.4. Core and legacy-adapter checks passed; the VST3 validator passed 47 tests. GUI appearance, full original-AU sound comparisons and real Ableton Live/FL Studio project recall still need your Mac tests. Test a copied project. Do not register both original and replacement VST2 plugins with the same ID.

The build artifact expires after 30 days. [Actions](https://github.com/kalmnet/CGPTCamelCrusherPort/actions/workflows/mac-plugins.yml) can rebuild it using Run workflow. The complete source and build instructions remain in this repository.

- [Verified findings and limitations](CamelCrusherPreservation/docs/FINDINGS.md)
- [Sound and host testing](CamelCrusherPreservation/docs/TESTING.md)
- [Old-project migration and recall](CamelCrusherPreservation/docs/MIGRATION.md)
- [Provenance and distribution limits](CamelCrusherPreservation/NOTICE.md)

The original AU is the user's working sound/parameter reference despite its black GUI. The original binaries and external SDK dependencies are not included. Windows DLL and JDMeet findings are in [the additional investigation report](CamelCrusherPreservation/docs/WINDOWS-AND-THIRD-PARTY.md). This private repository is for the requested preservation research; no public redistribution rights are asserted. AU reconstruction remains an experimental source target.
