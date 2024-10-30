package utils

import (
	"fmt"
	"os"
	"path/filepath"

	"gopkg.in/ini.v1"
)

type GitRepo struct {
	worktree string
	gitdir   string
	conf     *ini.File
}

func NewEmptyGitRepo() *GitRepo {
	return &GitRepo{
		worktree: "",
		gitdir:   "",
		conf:     nil,
	}
}

func (g *GitRepo) SetupRepo(path string, force bool) {
	g.worktree = path
	g.gitdir = filepath.Join(path, ".git")

	if !force {
		os.Stat(g.gitdir)
	}

	// reading configuration file in .git/config
	cf := RepoFile(g, false, "config")
	if cf != "" {
		if _, err := os.Stat(cf); err == nil {
			g.conf, _ = ini.Load(cf)
		} else if os.IsNotExist(err) {
			fmt.Println("Configuration file does not exist")
			if !force {
				panic("Configuration file missing")
			}
		} else {
			// Some other error occurred
			panic(fmt.Sprintf("Error checking configuration file: %v", err))
		}
	} else if !force {
		panic("Configuration file path is empty and force is not enabled")
	}
}

func (g *GitRepo) Worktree() string {
	return g.worktree
}

func (g *GitRepo) Gitdir() string {
	return g.gitdir
}
