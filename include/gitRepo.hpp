#ifndef GITREPO_H
#define GITREPO_H
#include <contants.hpp>
#include <filesystem>
#include <gitexceptions.hpp>
#include <string>

namespace fs = std::filesystem;

class GitRepository {
   private:
    std::string worktree;
    std::string gitdir;
    std::string conf;

   public:
    GitRepository(std::string path, bool force = false);

    std::string getGitDir();

    std::string getWorkTree();
};

#endif