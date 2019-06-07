import os, json, utils
import pprint

DOC_FILE = "doc.md"
INDENT = "  "

def genSnippetDoc(snippet, docLines, level):
	docLines.append(INDENT*level + "- `" + snippet["name"] + "`")
	subPrefix = INDENT*(level+1) + "- "
	props = snippet["properties"]

	if props["title"]:
		docLines[-1] += (" : " + "| ".join(props["title"]))

	if props["defines"]:
		defs = ", ".join(props["defines"])
		defs = ", ".join(["`" + fct.strip() + "`" for fct in defs.split(",")])
		docLines.append(subPrefix + "*Defines*: " + defs)

	if props["doc"]:
		doc = "\n".join(props["doc"])
		docLines.append(subPrefix + "*Documentation*: " + doc)

def genCategoryDoc(category, docLines, level):
	if level == 0:
		docLines.append("## " + category)
	else:
		docLines.append(INDENT * (level-1) + "- **" + category + "**")

def genTreeDoc(tree, docLines):
	level = tree["_level_"]
	excludeKeys = ["_contain_", "_level_"]

	for snippet in tree["_contain_"]:
		genSnippetDoc(snippet, docLines, level)
	for category in tree:
		if not category in excludeKeys:
			genCategoryDoc(category, docLines, level)
			genTreeDoc(tree[category], docLines)


snippetsDatas = utils.getAllSnippets()
tree = utils.getSnippetsTree(snippetsDatas)

docLines = []
genTreeDoc(tree, docLines)

with open(DOC_FILE, "w") as f:
	f.write("\n".join(docLines))