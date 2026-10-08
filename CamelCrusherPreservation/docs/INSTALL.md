# Install the Mac test plugins

These are preservation test builds. Sound, editor behavior and old-project recall still need testing on your Mac. Both plugins include native Apple Silicon ARM64 and Intel x86_64 code. Xcode is not needed to use them.

1. Extract the downloaded ZIP (if it contains another ZIP, extract that too).
2. In Finder, choose Go > Go to Folder and enter `~/Library/Audio/Plug-Ins/`.
3. Put `CamelCrusherPreservation.vst3` inside the `VST3` folder. Create that folder if necessary.
4. Restart your DAW and rescan plugins. Try the VST3 in a new empty project first.

The optional `CamelCrusher.vst` belongs in the `VST` folder. It reports the old CamelCrusher VST2 identity for project-recall experiments. Move the original CamelCrusher VST outside all scanned locations before installing this adapter; keep a backup. Do not install both same-ID VST2 versions together. Keep your functioning original AU available as the sound reference.

Always test a copy of an old project. Check saved settings, automation and sound before saving. VST3 does not automatically replace an old VST2 instance.

These builds have an ad hoc signature and are not Apple-notarized. If macOS blocks the plugin, record the exact warning and contact the maintainer for a specific fix. Do not disable system security settings.
