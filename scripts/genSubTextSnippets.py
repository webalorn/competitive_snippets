import os, utils

SNIPPET_FOLDER = "generated/sublimeTextSnippets"

for fileInfos in utils.getSnippetsFiles():
	with open(fileInfos['filepath'], "r") as cppFile:
		fLines = utils.removeFileComment(cppFile.readlines())

		newDirPath = os.path.join(SNIPPET_FOLDER, fileInfos['dirpath'])
		os.makedirs(newDirPath, exist_ok=True)

		newPath = os.path.join(newDirPath, fileInfos['name'] + '.sublime-snippet')
		content = "".join(fLines)
		content = utils.insertInTemplate("scripts/templates/sublimeSnippet", {
				"content": content,
				"name": fileInfos['name'],
			})

		with open(newPath, "w") as f:
			f.write(content)