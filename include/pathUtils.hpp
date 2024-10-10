#ifndef PATHUTILS_H
#define PATHUTILS_H
#include <gitRepo.hpp>
#include <string>
#include <vector>

class PathUtils {
   private:
    GitRepository &repo;

   public:
    PathUtils(GitRepository &repo);

    template <typename... Paths>
    std::string repo_path(Paths... paths);
    // TODO : repo_file, repo_dir

    template <typename... Paths>
    std::string create_file(bool mkdir = false, Paths... paths);

    template <typename... Paths>
    bool create_dir(bool mkdir = false, Paths... paths);
};

template <typename... Paths>
std::string PathUtils::repo_path(Paths... paths) {
    // Start with the base path, which is the git directory
    fs::path combined_path = fs::path(repo.getGitDir());
    std::vector<std::string> _paths = {paths...};
    for (auto i : _paths) {
        combined_path /= fs::path(i);
    }
    std::cout << combined_path;
    return combined_path.string();
}

template <typename... Paths>
std::string PathUtils::create_file(bool mkdir, Paths... paths) {
    std::vector<std::string> pathList = {paths...};
    if (PathUtils::create_dir(
            mkdir,
            std::vector<std::string>(pathList.begin(), pathList.end() - 1))) {
        return PathUtils::repo_path({paths...});
    }
    return "";
}

template <typename... Paths>
bool PathUtils::create_dir(bool mkdir, Paths... paths) {
    std::string path = PathUtils::repo_path(paths...);
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
