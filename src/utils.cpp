#include "utils.hpp"

Utils::Utils(GitRepository &repo) : repo(repo) {}

void Utils::write_to_file(std::string &&path, std::string &&content) {
    std::ofstream of;
    of.open(std::move(path));
    if (of.is_open()) {
        of << std::move(content);
        of.close();
        // std::cout << "File written successfully.\n"; in logs
    } else {
        throw GitException("Unable to open file for writing.\n");
    }
}

void Utils::create_default_configs() {
    std::string configFilePath =
        Utils::repo_path(repo.getGitDir(), "config.ini");
    mINI::INIFile file(configFilePath);
    mINI::INIStructure ini;
    ini["core"]["repositoryformatversion"] = "0";
    ini["core"]["filemode"] = "false";
    ini["core"]["bare"] = "false";
    file.generate(ini);
}
