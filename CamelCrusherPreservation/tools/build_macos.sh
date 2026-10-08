#!/bin/bash
set -euo pipefail
project_dir="$(cd "$(dirname "$0")/.." && pwd)"
: "${VST3_SDK_ROOT:?Set VST3_SDK_ROOT to the pinned recursive SDK checkout}"
build_dir="${CAMEL_BUILD_DIR:-$project_dir/build-macos}"
cmake -S "$project_dir" -B "$build_dir" -DCMAKE_BUILD_TYPE=Release \
 -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0 \
 -DVST3_SDK_ROOT="$VST3_SDK_ROOT" -DCAMEL_BUILD_LEGACY="${CAMEL_BUILD_LEGACY:-OFF}" \
 -DCAMEL_BUILD_AU="${CAMEL_BUILD_AU:-OFF}" -DAUDIOUNIT_SDK_ROOT="${AUDIOUNIT_SDK_ROOT:-}" \
 -DCAMEL_AU_LEGACY_ID="${CAMEL_AU_LEGACY_ID:-OFF}"
cmake --build "$build_dir" --config Release --parallel
ctest --test-dir "$build_dir" -C Release --output-on-failure
bundle="$build_dir/VST3/Release/CamelCrusherPreservation.vst3"
if [[ -d "$bundle" ]]; then
 lipo -archs "$bundle/Contents/MacOS/CamelCrusherPreservation"
 codesign --force --deep --sign - "$bundle"
 codesign --verify --deep --strict "$bundle"
 "$build_dir/bin/Release/validator" "$bundle"
fi
printf 'Build completed in %s. Installation is a separate manual step.\n' "$build_dir"
