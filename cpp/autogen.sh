#!/bin/sh
#-------------------------------------------------------------------
# Helper script to regenerate autotools files from definitions.
#-------------------------------------------------------------------

# Check for required directories.
mkdir -p config m4

# Generate the needed files from our configuration.
autoreconf --force --install -I config -I m4
