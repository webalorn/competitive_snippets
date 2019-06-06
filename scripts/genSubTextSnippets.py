import os, utils

SNIPPET_FOLDER = "generated/sublimeTextSnippets"

for snippet in utils.getAllSnippets():
	newDirPath = os.path.join(SNIPPET_FOLDER, snippet['dirpath'])
	os.makedirs(newDirPath, exist_ok=True)

	newPath = os.path.join(newDirPath, snippet['name'] + '.sublime-snippet')
	content = "\n".join(snippet["code"])
	content = utils.insertInTemplate("scripts/templates/sublimeSnippet", {
			"content": content,
			"name": snippet['name'],
		})

	with open(newPath, "w") as f:
		f.write(content)