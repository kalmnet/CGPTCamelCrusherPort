# Finalized preservation build

## User acceptance: finalized build 0.1.1

The user reports successful testing of both VST2 and VST3 in native Ableton Live 12.4.6 and FL Studio 26.1.7 build 5419. The VST2 editor now renders in both hosts, controls and preset selection work, and VST3 discovery in Live recovered after the initial macOS security/scan failure. The user also reports successful VST2 project recall from Windows to Mac and from Mac back to Windows using the original Windows DLL.

These are user-reported acceptance results for the tested setup/projects. They are distinct from binary differential tests and CI evidence. They do not establish sample-perfect full-plugin sound equivalence, every automation path, every project/DAW version, or new AU support. Exact full-original-AU comparison renders remain pending.

The released binaries are the exact bundles from successful Mac run 37824633602 (plugin-source commit 88d61e500ecc3f756f2b3416b969568633604d27), which the user tested. They were not rebuilt or given new DSP/state/identity changes during finalization. Source/docs release contents include subsequent Windows research and acceptance documentation. The release identifier and VST3 version are 0.1.1; original VST2 identity/version remain intact for compatibility.
