# Install CamelCrusher Preservation AU 0.2.0

No coding or Xcode is needed.

1. Quit your DAW and extract the downloaded ZIP.
2. In Finder choose Go > Go to Folder and enter `~/Library/Audio/Plug-Ins/Components/`. Create the Components folder if necessary.
3. Copy `CamelCrusherAU.component` into that folder.
4. Reopen your DAW and enable Audio Units. In Live, enable Audio Units in Settings > Plug-Ins and rescan; if an earlier security block left a failed scan, hold Option while clicking Rescan after approving the specific plugin.
5. Find **Preservation Research: CamelCrusher**, or search CamelCrusher. Test a new empty project first.

The bundle includes native Apple Silicon ARM64 and Intel x86_64 code. It uses the recovered DSP and original interface.

This AU has its own identity (`aumf / CrP1 / Prsv`). It can coexist with the original AU. It does not automatically replace original AU instances or VST2 instances in old projects. Your existing VST2/VST3 plugins can remain installed.

The build is ad hoc signed, not Apple notarized. If macOS blocks this specific component, retain the exact warning; use the normal macOS approval flow rather than disabling security globally.

Test knobs, module buttons, all presets, automation, saving/reopening, multiple instances and offline rendering in your DAW. CI validates the adapter and editor, but these real-host tests still need confirmation.

The optional source setting CAMEL_AU_LEGACY_ID uses the original AU identity and would collide with the original component. That replacement configuration is not part of this download or certified for original-AU project recall.
