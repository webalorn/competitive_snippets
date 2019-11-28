import os, utils

SNIPPET_FOLDER = "generated/sublimeTextSnippets"
LANGS = {
	"cpp": "c++",
	"py": "python"
}

for snippet in utils.getAllSnippets():
	newDirPath = os.path.join(SNIPPET_FOLDER, snippet['dirpath'])
	os.makedirs(newDirPath, exist_ok=True)

	newPath = os.path.join(newDirPath, snippet['name'] + '.sublime-snippet')
	content = "\n".join(snippet["code"])
	content = utils.insertInTemplate("scripts/templates/sublimeSnippet", {
			"content": content,
			"name": snippet['name'],
			"lang": LANGS[snippet['lang']],
		})

	with open(newPath, "w") as f:
		f.write(content)