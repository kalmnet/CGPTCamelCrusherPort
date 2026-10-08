# Old Live and FL Studio projects

The priority is restoring each old VST2 instance with its exact saved normalized parameters, program selection, unused slots and automation. A new VST3 with the same display name cannot be assumed to replace an old VST2. The new VST3 uses a separate processor identity. It does not claim an automatic VST2-to-VST3 replacement mapping.

The optional legacy adapter instead reports CamelCrusher, ID `CaCr`, 17 parameters in the original order and 20 programs. It accepts and emits the recovered raw single-program and bank chunks. These properties have passed the included ABI smoke test. They are necessary compatibility evidence, but Live and FL Studio may also use the saved plugin path/name, architecture, platform metadata, wrapper state and project-specific identifiers. Actual project recall remains unverified.

## Safe recall experiment

1. Duplicate the project and retain an untouched original. Record the DAW version, platform, sample rate, plugin format and any missing-plugin message. Archive the original plugin bundle separately.
2. While the original is still installed, export any accessible instance as FXP/FXB. Record all 17 host parameter values, active program and automation lanes. Do not infer the selected program from a raw bank. Record disabled/bypassed modules too: those stored values matter later.
3. Build and validate the legacy adapter using README.md. Move the original VST outside all scanned plugin locations before testing the new same-ID bundle. Do not install two `CaCr` VST2 implementations simultaneously. Keep the working original AU available as a separate sound reference.
4. Rescan the DAW and create a new VST2 instance first. Verify knobs and generic host parameters both change the sound, all controls are present, and saving/reopening a test project retains values.
5. Open the duplicated old project. Verify that the instance actually resolves to the new adapter. Check every normalized parameter, active program, unused values, host bypass and automation assignments against the baseline. Render without changing settings. Do not overwrite the original project while compatibility is uncertain.
6. Save the tested copy under a new name, close the DAW completely, reopen, and repeat the value and render checks. Test multiple instances with different presets, frozen tracks, disabled effects and automation. A successful single instance does not certify every project.

For Windows-origin Live projects, transfer the complete project/assets and confirm the DAW's cross-platform plugin lookup. For FL Studio, confirm that the Mac version can read the specific Windows project's wrapper state and find the registered VST2 effect. The subsequently supplied Windows DLL confirms the same identity/parameter order/state serialization, and selected distortion/compressor comparisons match. Full platform DSP equality and automatic host lookup across all projects are not certified. The user reports successful recall of tested old Windows instances; exact values, automation and renders still need comparison.

## Explicit migration to VST3

If automatic legacy recall fails but the old settings can be exported, convert FXP/FXB with tools/presets.py and load the resulting VST3 preset into a new instance. Choose the current program explicitly for a bank. Preserve the old instance disabled in the copied project until the new one is verified. Reconnect and verify each automation lane manually: matching parameter numbers alone does not make a host migrate lanes across formats.

The converter preserves all 17 float32 slots, including the five unused values. The VST3's new component envelope stores the 20-program bank and selected index. Preset import and normalized-value preservation are tested; the DAW-specific act of replacing a device is not.

## AU as the sound reference

The user reports that the original AU changes sound despite its black GUI, while the original VST does not respond audibly to parameters. Use the AU's generic parameter interface or the Rosetta reference renderer in TESTING.md. Do not use the nonresponsive VST as the sole sound baseline, and do not assume an AU instance automatically receives a VST2 instance's saved state.

The new AU defaults to a separate identity. Enabling the old AU identity is an explicit collision/recall experiment requiring the original component to be moved out of scanned locations. AU is secondary to the VST3 and legacy project requirements.
