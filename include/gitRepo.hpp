#ifndef GITREPO_H
#define GITREPO_H
#include <contants.hpp>
#include <filesystem>
#include <gitexceptions.hpp>
#include <string>

namespace fs = std::filesystem;

class GitRepo {
   private:
    std::string worktree;
    std::string gitdir;
    std::string conf;

   public:
    GitRepo(const std::string path, bool force = false) {
        worktree = path;
        gitdir = fs::path(worktree) / DOTGIT;

        if (!(force || (fs::exists(gitdir) && fs::is_directory(gitdir)))) {
            throw GitException("Not a Git repository" + worktree);
        }
    }

    std::string getGitDir() const { return this->gitdir; }
};

#endif