# CamelCrusher preservation source

Start with [the build instructions](CamelCrusherPreservation/README.md). The complete source is in `CamelCrusherPreservation/`; an equivalent source archive is `CamelCrusherPreservation-source.zip`.

The selected Intel DSP comparisons reported zero sample error for both supplied binaries. Portable core, Linux VST3 and optional legacy-adapter checks passed. **macOS ARM64 compilation, the Cocoa editor, full original-AU Rosetta comparisons, and actual Ableton Live/FL Studio project recall remain unverified. No ready-to-install ARM64 binary is included.**

- [Verified findings and limitations](CamelCrusherPreservation/docs/FINDINGS.md)
- [Mac testing procedures](CamelCrusherPreservation/docs/TESTING.md)
- [Old-project migration and recall](CamelCrusherPreservation/docs/MIGRATION.md)
- [Provenance and distribution limits](CamelCrusherPreservation/NOTICE.md)

The original AU is the user's working parameter/sound reference despite a black GUI. The original VST's reported nonresponsive parameters are not reproduced here. A VST3 alone is not assumed to replace an old VST2 instance.

The original executable binaries and external SDK dependencies are not included. Keep the original archive for repeating the Intel machine-code comparisons. This private repository is for the requested preservation research; no public redistribution rights are asserted.
