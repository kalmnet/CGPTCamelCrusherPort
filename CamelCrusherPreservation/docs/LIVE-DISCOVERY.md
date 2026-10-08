# VST3 rediscovery in Live 12.4.6

The user confirmed correct installation and enabled system VST3 folders, then reported that macOS blocked the initial scan. Live may retain that failed result after security approval.

1. Keep the intended single CamelCrusherPreservation.vst3 installed in `~/Library/Audio/Plug-Ins/VST3/`.
2. Quit Live completely and reopen it after the macOS approval already given.
3. Open Settings > Plug-Ins. Hold Option while clicking Rescan to request a complete rescan rather than relying on cached results.
4. Search All plug-ins for CamelCrusher Preservation. Test a new empty project before testing old copies.

If macOS blocks this specific bundle again, retain the exact message. Do not disable system security globally or remove unrelated cache files. If it remains missing, the relevant evidence is Live's scanner/error log: in Finder use Go > Go to Folder and enter `~/Library/Preferences/Ableton/Live 12.4.6/`. Preserve Log.txt and any PluginScanner log present. These logs may contain local paths; share only what you intend to disclose.

The native VST3 build passed its SDK validator and loads in the user's FL Studio. That narrows the investigation but does not establish why Live rejected it. A full rescan is a targeted troubleshooting step, not a verified fix yet.
