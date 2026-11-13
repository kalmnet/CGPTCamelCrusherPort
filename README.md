# CamelCrusher preservation — finalized 0.1.1

[Download the finalized Mac plugins](https://github.com/kalmnet/CGPTCamelCrusherPort/releases/tag/v0.1.1). No coding or Xcode is needed to install them. Read [installation steps](CamelCrusherPreservation/docs/INSTALL.md).

The package contains `CamelCrusher.vst` (VST2, for original project compatibility) and `CamelCrusherPreservation.vst3`. Both include native Apple Silicon ARM64 and Intel x86_64 code. Use VST2 for projects exchanged with Windows using the original CamelCrusher DLL; VST3 does not automatically replace old VST2 instances.

The user confirmed both plugins work in native Live 12.4.6 and FL Studio 26.1.7 build 5419, including restored GUI/controls. Tested VST2 projects recall in both Windows-to-Mac and Mac-to-Windows directions. [Acceptance and limits](CamelCrusherPreservation/docs/ACCEPTANCE.md) separates these user reports from automated verification.

The release preserves the tested 0.1.1 binaries. The Apple Silicon CI build passed core/legacy tests, preset checks and 47 VST3 validator tests. Selected original Intel DSP tests matched exactly in their stated experiments; Windows selected distortion/compressor tests also matched. Full original-plugin comparison renders remain pending. The completed AU is available separately; see below.

- [Verified findings](CamelCrusherPreservation/docs/FINDINGS.md)
- [Testing procedures](CamelCrusherPreservation/docs/TESTING.md)
- [Project migration](CamelCrusherPreservation/docs/MIGRATION.md)
- [Windows and third-party investigation](CamelCrusherPreservation/docs/WINDOWS-AND-THIRD-PARTY.md)
- [Source build instructions](CamelCrusherPreservation/README.md)
- [Provenance and distribution limits](CamelCrusherPreservation/NOTICE.md)

This private repository is for the requested preservation work. Original executable binaries and third-party port assets/code are not included; no public redistribution rights are asserted.

## Audio Unit replacement

[Download CamelCrusher AU](https://github.com/kalmnet/CGPTCamelCrusherPort/releases/tag/au-v0.2.1). The file and plugin name are **CamelCrusher**, with the original Camel Audio identity. It replaces the unsupported AU. Back up and move the original component outside scanned folders before installing this one; also remove the earlier separate CamelCrusherAU.component if installed. [Installation](CamelCrusherPreservation/docs/AU-INSTALL.md) · [verification](CamelCrusherPreservation/docs/AU-STATUS.md). Old AU project recall still needs confirmation in a copied project. VST2/VST3 binaries remain unchanged.
