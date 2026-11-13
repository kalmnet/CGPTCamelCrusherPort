# Install CamelCrusher

The plugin is named **CamelCrusher** and the bundle is **CamelCrusher.component**, matching the original AU. It uses the original component identity: aumf / CaCr / CamA, and original bundle identifier com.camelaudio.au.CamelCrusher.

1. Quit your DAW.
2. Move the old CamelCrusher.component to a backup folder outside all plug-in scan locations.
3. Extract this download and put the new CamelCrusher.component in the same Components folder as the old one. Common folders are ~/Library/Audio/Plug-Ins/Components/ and /Library/Audio/Plug-Ins/Components/.
4. If you installed the earlier separate CamelCrusherAU.component, move it outside scanned folders too. Keep just one CamelCrusher AU implementation registered.
5. Reopen your DAW, rescan Audio Units, and look for CamelCrusher under Camel Audio. In Live, hold Option while clicking Rescan if it retains a failed scan.
6. Open a COPY of an old AU project and verify its saved settings, automation and sound before saving.

This replaces the unsupported AU identity; it is not a separately named plugin. It includes native Apple Silicon ARM64 and Intel x86_64 code. Your VST2/VST3 installations are separate formats.

The original ID and investigated state formats pass automated tests. Actual reopening of your old AU projects still needs confirmation in your DAW. Keep the original component and untouched projects backed up.

The download revision is 0.2.1. The plugin retains the original displayed version 1.01; bundle/component revision 1.01.1 distinguishes this native build from the old binary for scanning. This is an independent reconstruction, not an official Camel Audio release; see NOTICE.md.

The bundle is ad hoc signed, not Apple notarized. If macOS blocks this specific component, use its normal approval flow and rescan. Do not disable system security globally.
