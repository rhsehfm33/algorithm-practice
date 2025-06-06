#!/bin/bash

BASE_DIR="/home/c++"
TEMPLATE="$BASE_DIR/sol.cpp"

if [ -z "$2" ]; then
  TARGET_DIR="$BASE_DIR/$1"
else
  TARGET_DIR="$BASE_DIR/codeforces/$1/$2"
fi

mkdir -p "$TARGET_DIR"
cp "$TEMPLATE" "$TARGET_DIR/"
cd "$TARGET_DIR"
code "sol.cpp"
