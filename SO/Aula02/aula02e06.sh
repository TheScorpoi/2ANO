#!/bin/bash
#Parameter Expansion
file="$HOME/.bashrc"
echo "File path: $file"
echo "File name: ${file##*/}"
echo "Directory name: ${file%/*}"
