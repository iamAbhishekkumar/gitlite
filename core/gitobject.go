package core

import (
	"fmt"
)

type GitObject interface {
	Serialize() string
	Deserialize(data []byte)
	Init()
}

type BaseGitObject struct {
	ObjType string
}

func (b *BaseGitObject) Serialize() string {
	return ""
}

func (b *BaseGitObject) Deserialize(data []byte) {
}

func (b *BaseGitObject) Init() {}

func NewGitObject(objType string, data []byte) (GitObject, error) {
	var obj GitObject

	switch objType {
	case "commit":
		obj = NewGitCommit(data, "commit")
	case "tree":
		obj = NewGitTree(data)
	case "tag":
		obj = NewGitCommit(data, "tag")
	case "blob":
		obj = NewGitBlob(data)
	default:
		return nil, fmt.Errorf("unknown Git object type: %s", objType)
	}

	return obj, nil
}
