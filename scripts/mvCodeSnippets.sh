#!/bin/sh
if [ -z "$VSCODE_SNIPPETS" ]
then
      echo "Please set \$VSCODE_SNIPPETS to your VS Code user snippets directory if you want this script to automaticly copy the VS Code snippets file to your snippets directory"
else
      cp generated/vscodeSnippets/competitive_snippets.code-snippets "$VSCODE_SNIPPETS/competitive_snippets.code-snippets"
      echo "competitive_snippets.code-snippets has been copied in $VSCODE_SNIPPETS"
fi