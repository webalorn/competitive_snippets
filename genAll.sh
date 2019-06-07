#!/bin/sh
rm -r generated/*
python3 scripts/genSubTextSnippets.py && echo "Generated for Sublime Text 3"
python3 scripts/genVSCodeSnippets.py && echo "Generated for VS Code"
scripts/mvCodeSnippets.sh