#!/bin/sh
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/ben/Applications/Qt/5.13.1/clang_64/bin/uic "$@"
