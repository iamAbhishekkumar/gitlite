#ifndef UTILS_H
#define UTILS_H
#include <gitRepo.hpp>
#include <string>
class Utils {
   private:
   public:
    // static variadic fucntion
    template <typename... Paths>
    static std::string repo_path(GitRepo repo, Paths... paths);
    // TODO : repo_file, repo_dir
};

Utils::Utils(/* args */) {}

Utils::~Utils() {}

#endif