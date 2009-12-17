#!/bin/bash
set -eu

# Hack to allow calling this script from it's dir.
if [ -f svg_grayscale.pasprogram ]; then
  cd ../../
fi

# Call this from ../../ (or just use `make examples').

fpc -dRELEASE @kambi.cfg examples/base/svg_grayscale.pasprogram
