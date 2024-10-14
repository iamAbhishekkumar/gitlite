#include <iostream>

#include "argParser.hpp"
#include "gitRepo.hpp"
#include "utils.hpp"

void repo_create(std::string path) {
    GitRepository repo(path, true);
    Utils pu(repo);

    if (fs::exists(repo.getWorkTree())) {
        if (!(fs::is_directory(repo.getWorkTree())))
            throw GitException(repo.getWorkTree() + " is not a directory!");
        if (fs::is_directory(repo.getGitDir()) &&
            fs::is_empty(repo.getGitDir()))
            throw GitException(repo.getGitDir() + " is not a empty!");
    } else
        fs::create_directories(repo.getWorkTree());

    pu.create_dir(true, "branches");
    pu.create_dir(true, "objects");
    pu.create_dir(true, "refs", "tags");
    pu.create_dir(true, "refs", "heads");

    pu.write_to_file(pu.create_file(false, "description"),
                     "Unnamed repository; edit this file 'description' to name "
                     "the repository.\n");

    pu.write_to_file(pu.create_file(false, "HEAD"), "ref: refs/heads/main\n");
    pu.create_default_configs();
}

int main(int argc, char* argv[]) {
    // if (argc == 1) {
    //     std::cout << "No arguments provided.!!!" << std::endl;
    //     return -1;
    // }

    // ArgParser argParser(argc, argv);

    // if (argc == 2 && std::string_view(argv[1]) == "init") {
    //     std::cout << "Initialize empty gitlite repository in
    //     <current_dir_path>"
    //               << std::endl;
    //     // Add logic for initialization
    //     return 0;  // Exit after handling "init"
    // }

    // // Check for "-h" flag
    // if (argParser.cmdOptionExists("-h")) {
    //     std::cout << "Help requested" << std::endl;
    //     // Show help message
    //     return 0;  // Exit after showing help
    // }

    // // Get filename after "-f" option
    // auto filename = argParser.getCmdOption("-f");
    // if (filename) {
    //     std::cout << "Filename: " << *filename << std::endl;
    //     // Do something with the filename
    //     return 0;
    // }

    repo_create("/home/gymy/dev/gitLite/gitSample");
    std::cout << std::endl;

    // std::cout << "Unknown command entered!!!" << std::endl;

    return 0;
}
