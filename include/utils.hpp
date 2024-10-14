#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <string>
#include <vector>

#include "gitRepo.hpp"
#include "iniHandler.hpp"

class Utils {
   private:
    GitRepository &repo;

   public:
    Utils(GitRepository &repo);

    template <typename... Paths>
    std::string repo_path(Paths... paths);
    // TODO : repo_file, repo_dir

    template <typename... Paths>
    std::string create_file(bool mkdir = false, Paths... paths);

    template <typename... Paths>
    bool create_dir(bool mkdir = false, Paths... paths);

    void write_to_file(std::string &&path, std::string &&content);
    void create_default_configs();
};

template <typename... Paths>
std::string Utils::repo_path(Paths... paths) {
    // Start with the base path, which is the git directory
    fs::path combined_path = fs::path(repo.getGitDir());
    std::vector<std::string> _paths = {paths...};
    for (auto i : _paths) {
        combined_path /= fs::path(i);
    }
    return combined_path.string();
}

template <typename... Paths>
std::string Utils::create_file(bool mkdir, Paths... paths) {
    std::string finalPath = Utils::repo_path(paths...);
    if (mkdir &&
        Utils::create_dir(mkdir, fs::path(finalPath).parent_path().string())) {
        return finalPath;
    }
    return finalPath;
}

template <typename... Paths>
bool Utils::create_dir(bool mkdir, Paths... paths) {
    std::string path = Utils::repo_path(paths...);
    if (fs::exists(path)) {
        if (fs::is_directory(path))
            return true;
        else
            throw GitException("Not a directory !!!!" + path);
    }

    if (mkdir) {
        fs::create_directories(path);
        return true;
    }
    return false;
}

#endif
