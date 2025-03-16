package core

type GitBlob struct {
	BaseGitObject
	BlobData []byte
}

func NewGitBlob(data []byte) *GitBlob {
	return &GitBlob{
		BaseGitObject: BaseGitObject{ObjType: "blob"},
		BlobData:      data,
	}
}

func (b *GitBlob) Serialize() string {
	return string(b.BlobData)
}

func (b *GitBlob) Deserialize(data []byte) {
	b.BlobData = data
}
