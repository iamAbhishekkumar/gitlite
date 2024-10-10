#include <../include/gitRepo.hpp>

GitRepository::GitRepository(std::string path, bool force) {
    worktree = path;
    gitdir = fs::path(worktree) / DOTGIT;

    if (!(force || (fs::exists(gitdir) && fs::is_directory(gitdir)))) {
        throw GitException("Not a Git repository" + worktree);
    }
}

std::string GitRepository::getGitDir() { return this->gitdir; }

std::string GitRepository::getWorkTree() { return this->worktree; }
