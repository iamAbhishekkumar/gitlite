#include <../include/utils.hpp>

Utils::Utils(GitRepository &repo) : repo(repo) {}

void Utils::write_to_file(std::string &&path, std::string &&content) {
    std::ofstream of;
    of.open(std::move(path));
    if (of.is_open()) {
        of << std::move(content);
        of.close();
        std::cout << "File written successfully.\n";
    } else {
        throw GitException("Unable to open file for writing.\n");
    }
}
