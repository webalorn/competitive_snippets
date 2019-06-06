import os, json, utils

SNIPPET_FOLDER = "generated/vscodeSnippets"
SNIPPET_FILE_NAME = "competitive_snippets.code-snippets"
SNIPPET_FILE = os.path.join(SNIPPET_FOLDER, SNIPPET_FILE_NAME)

snippetsDatas = {}

for snippet in utils.getAllSnippets():
	snippetsDatas[snippet['name']] = {
		'prefix': snippet['name'],
		'body': snippet['code'],
		'description' : "\n".join(snippet['properties']['doc']),
		'scope': 'cpp',
	}

os.makedirs(SNIPPET_FOLDER, exist_ok=True)
with open(SNIPPET_FILE, "w") as f:
	json.dump(snippetsDatas, f)