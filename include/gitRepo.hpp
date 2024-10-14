#ifndef GITREPO_H
#define GITREPO_H
#include <filesystem>
#include <string>

#include "contants.hpp"
#include "gitexceptions.hpp"

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