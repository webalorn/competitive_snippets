import os

def getSnippetsFiles():
	files = []
	for (dirpath, dirnames, filenames) in os.walk("algos"):
		newDir = "/".join(["algos"]+dirpath.split("/")[1:])
		os.makedirs(newDir, exist_ok=True)

		for fName in filenames:
			if os.path.splitext(fName)[1] == '.cpp':
				fileInfos = {
					'filepath': os.path.join(dirpath, fName),
					'name': os.path.splitext(fName)[0],
					'dirpath': os.path.join(*(dirpath.split(os.path.sep)[1:])),
				}
				files.append(fileInfos)
	return files

def insertInTemplate(templatePath, blocks):
	with open(templatePath, "r") as f:
		template = "".join(f.readlines())
		for name, content in blocks.items():
			seq = "{{{" + name + "}}}"
			template = template.replace(seq, content)
		return template

def removeFileComment(fileLines):
	return [l for l in fileLines if l[:1] != "@" and l[:3] != "/*@"]