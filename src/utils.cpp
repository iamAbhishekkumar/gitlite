#include <../include/utils.hpp>

template <typename... Paths>
std::string Utils::repo_path(GitRepo repo, Paths... paths) {
    fs::path combined_path;
    // Fold expression (C++17) to combine all paths
    // "combined_path /= some_path" use to append one path to another
    combined_path /= (... /= fs::path(paths));
    return fs::path(repo.getGitDir()) / combined_path;
}
