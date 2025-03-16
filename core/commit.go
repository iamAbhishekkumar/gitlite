package core

type GitCommit struct {
	BaseGitObject
	Kvlm string
}

func NewGitCommit(data []byte, objType string) *GitCommit {
	return &GitCommit{
		BaseGitObject: BaseGitObject{ObjType: objType},
		Kvlm:          string(data),
	}
}

func (c *GitCommit) Serialize() string {
	return KVLMSerialize(c.Kvlm)
}

func (c *GitCommit) Deserialize(data []byte) {
	c.Kvlm = KVLMParse(data)
}

func KVLMParse(data []byte) string {
	return ""
}

func KVLMSerialize(data string) string {
	return ""
}
