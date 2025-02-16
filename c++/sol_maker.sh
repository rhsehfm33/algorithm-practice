#!/bin/bash
mkdir -p "$1"
if [ -z "$2" ]; then
  cp "/home/sol.cpp" "$1"
  code "$1/sol.cpp"
else
  cp "$2" "$1"
  code "$1/$(basename "$2")"
fi
cd "$1"
