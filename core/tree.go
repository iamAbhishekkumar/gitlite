package core

type GitTree struct {
	BaseGitObject
	Items []string
}

func NewGitTree(data []byte) *GitTree {
	return &GitTree{
		BaseGitObject: BaseGitObject{ObjType: "tree"},
		Items:         []string{},
	}
}

func (t *GitTree) Serialize() string {
	return TreeSerialize(t.Items)
}

func (t *GitTree) Deserialize(data []byte) {
	t.Items = TreeParse(data)
}

func TreeParse(data []byte) []string {
	return []string{}
}

func TreeSerialize(data []string) string {
	return ""
}
