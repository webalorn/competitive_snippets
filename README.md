# C++ Snippets for Competitive Programming

Theses snippets are aimed essentialy for competitive programming. The generators currently generate snippets for Sublime Text 3, and Visual Studio Code.

The snippet [cheatsheet can be found here](snippets.md).

## Usage

Snippets must first be generated, and then added to your editor.

To generate all snippets, type:

```bash
./genAll.sh
```

The documenation will be generated in the file [doc.md](doc.md)

## Generated Code Snippets

- Sublime text snippets location: `generated/sublimeTextSnippets`
- Visual Studio Code snippets location: `generated/vscodeSnippets/competitive_snippets.code-snippets`

### How to include in your editor

#### For Sublime Text 3
Because snippets can be placed in subfolders, you  have to put a symbolic link from your Sublime Text snippets directory (you can find it by trying to create a new snippet under Tools > Developer > New snippet, and trying to save. The prompted window should be located at this place). You can also just copy the folder, but do not forget to do this every time you update theses snippets.

#### For VS Code
You have to copy the file located at `generated/vscodeSnippets/competitive_snippets.code-snippets` in your User snippets directory. To do this automaticly, your can set the environment variable `$VSCODE_SNIPPETS`. It must contain the path to the snippets folder. The script `./mvCodeSnippets.sh` will move them automaticly. This script is always called after executing `./genAll.sh`.

## Snippets files format

Snippets files must contain C++ code and comments. The code of file will be the snippet itself, aside from the lines starting with `//@`.

### Names and category of a snippet

The name and category of snippet are set by the name of the file and the path to the file. The subfolders of the `snippets` folder within a snippet file is found will be its categories. The name of the snippet will be the filename without the `.cpp` extension. This name will also be the prefix you must type into your code editor to insert this snippet.

### Meta informations

Lines starting with `//@` will be considered as meta informations and will not be included in the snippet code. These lines will have a property name and a value, following this format:
```cpp
//@name This is the value of the property
```

For example:
```cpp
//@doc This is a documentation line
```

Available property names:
- **title**: A name for the snippet. Currently unused.
- **doc**: Documentation for the snippet. Currently unused.
- **defines**: List of functions / objects defined by this snippet. Currently unused.
- **include**: include another snippet code into this snippet.

You can also add a blank line that won't be included into the snippet code by typing:
```cpp
//@
```
This line will just be ignored.