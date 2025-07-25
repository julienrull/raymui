#!/bin/sh

# This script make microui usable as a singler header library with raylib. 

RAYMUI_HEADER="./src/raymui.h"
RAYMUI_SRC="./src/raymui.c"
MICROUI_HEADER="./src/microui.h"
MICROUI_SRC="./src/microui.c"
SINGLE_HEADER_LIB="./raymui.h"


cp "$MICROUI_HEADER" "$SINGLE_HEADER_LIB"
grep -v '#include *"microui.h"' "$RAYMUI_HEADER" >> "$SINGLE_HEADER_LIB"
echo "#ifdef RAYMUI_IMPLEMENTATION" >> "$SINGLE_HEADER_LIB"
grep -v '#include *"microui.h"' "$MICROUI_SRC" >> "$SINGLE_HEADER_LIB"
grep -v '#include *"raymui.h"' "$RAYMUI_SRC" >> "$SINGLE_HEADER_LIB"
echo "#endif // RAYMUI_IMPLEMENTATION" >> "$SINGLE_HEADER_LIB"
