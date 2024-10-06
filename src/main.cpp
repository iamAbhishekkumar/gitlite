#include <../include/argParser.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "No arguments provided.!!!" << std::endl;
        return -1;
    }

    ArgParser argParser(argc, argv);

    if (argc == 2 && std::string_view(argv[1]) == "init") {
        std::cout << "Initialize empty gitlite repository in <current_dir_path>"
                  << std::endl;
        // Add logic for initialization
        return 0;  // Exit after handling "init"
    }

    // Check for "-h" flag
    if (argParser.cmdOptionExists("-h")) {
        std::cout << "Help requested" << std::endl;
        // Show help message
        return 0;  // Exit after showing help
    }

    // Get filename after "-f" option
    auto filename = argParser.getCmdOption("-f");
    if (filename) {
        std::cout << "Filename: " << *filename << std::endl;
        // Do something with the filename
        return 0;
    }

    std::cout << "Unknown command entered!!!" << std::endl;
}
