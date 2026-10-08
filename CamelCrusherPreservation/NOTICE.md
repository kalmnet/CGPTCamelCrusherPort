# Provenance and distribution limits

This is an independent research reconstruction, not an official Camel Audio release. The supplied executable images, original skin PNGs, factory bank, symbols and selected decompiled evidence originate from the user-provided archive. A Windows DLL and third-party JDMeet port were subsequently supplied and inspected separately; see docs/WINDOWS-AND-THIRD-PARTY.md. The third-party code/assets were not incorporated into the plugin. Ownership of those original materials remains with their rights holders; this package does not grant a license to redistribute them or use the Camel Audio name as an endorsement.

The manual includes a license agreement. It is evidence concerning the supplied product, not an instruction from the user, and it does not establish that a new reconstruction or distribution of the original artwork is licensed. Keep this package for the authorized preservation investigation; obtain an appropriate rights review before public distribution. No legal conclusion about reverse engineering exceptions is asserted here.

The original executables are not included in this source package. The original GUI artwork, factory values, small bank test fixture and selected decompilation are included for review of the reconstruction. Removing those assets alone does not constitute a rights clearance.

The default VST3 build uses an external Steinberg VST3 SDK at the pinned revision in README.md. That revision's SDK source is MIT licensed; dependencies and submodules have their own notices. Retain their upstream license notices when distributing builds. The optional AU target uses Apple's Apache-2.0 AudioUnitSDK; retain its license and notices as applicable. Neither SDK is bundled here.

The optional legacy adapter declares the necessary ABI independently in src/LegacyAbi.h. It contains no downloaded Steinberg VST2 SDK headers or implementation. ABI interoperability does not by itself resolve trademark, contract, patent or distribution questions. The user requested investigation where licensing permits; the adapter is opt-in research source, not a representation that public VST2 distribution has been cleared.

The new C++ and tools were produced for this preservation request. No blanket license is assigned here to a package containing both newly written code and original proprietary assets/evidence. Do not interpret the external SDK licenses as licensing the original CamelCrusher assets.
