package core

import (
	"fmt"
	"log"
	"os"
	"path/filepath"

	"gopkg.in/ini.v1"
)

func RepoPath(gitrepo *GitRepo, path ...string) string {
	return filepath.Join(append([]string{gitrepo.Gitdir()}, path...)...)
}

func RepoDir(gitrepo *GitRepo, mkdir bool, path ...string) (string, error) {
	gitPath := RepoPath(gitrepo, path...)
	info, err := os.Stat(gitPath)
	if err == nil {
		if info.IsDir() {
			return gitPath, nil
		} else {
			fmt.Printf("Not a directory %s\n", gitPath)
			return "", err
		}
	}

	if mkdir {
		err := os.MkdirAll(gitPath, os.ModePerm)
		if err != nil {
			fmt.Printf("Error creating directory\n")
			return "", err
		}
	}
	return "", nil
}

func RepoFile(gitrepo *GitRepo, mkdir bool, path ...string) string {
	_, err := RepoDir(gitrepo, mkdir, path[:len(path)-1]...)
	if err == nil {
		return RepoPath(gitrepo, path...)
	}
	return ""
}

func WriteToRepoFile(filepath string, content string) {
	err := os.WriteFile(filepath, []byte("Hell"), 0644)
	if err != nil {
		panic(fmt.Sprintf("Unable to write to the file %s", filepath))
	}
}

func RepoDefaultConfig(path string) {
	cfg := ini.Empty()
	addKey(cfg, "core", "repositoryformatversion", "0")
	addKey(cfg, "core", "filemode", "false")
	addKey(cfg, "core", "bare", "false")
	err := cfg.SaveTo(path)
	if err != nil {
		log.Fatalf("Failed to save file: %v", err)
	}
}

func RepoCreate(path string) *GitRepo {
	repo := NewEmptyGitRepo()
	repo.SetupRepo(path, true)

	if info, err := os.Stat(repo.Worktree()); err == nil {
		if !info.IsDir() {
			panic(fmt.Sprintf("%s is not a directory!", repo.Worktree()))
		} else if _, err := os.Stat(repo.Gitdir()); err == nil {
			files, _ := os.ReadDir(repo.Gitdir())
			if len(files) > 0 {
				panic(fmt.Sprintf("%s is not empty!", repo.Gitdir()))
			}
		} else {
			if err := os.MkdirAll(repo.Worktree(), os.ModePerm); err != nil {
				panic(fmt.Sprintf("Failed to create worktree directory: %v", err))
			}
			fmt.Println("Worktree directory created successfully")
		}
	}

	RepoDir(repo, true, "branches")
	RepoDir(repo, true, "objects")
	RepoDir(repo, true, "refs", "tags")
	RepoDir(repo, true, "refs", "heads")

	WriteToRepoFile(RepoFile(repo, true, "description"), "Unnamed repository; edit this file 'description' to name the repository.\n")
	WriteToRepoFile(RepoFile(repo, false, "HEAD"), "ref refs/heads/master\n")
	RepoDefaultConfig(RepoFile(repo, false, "config"))
	return repo
}
