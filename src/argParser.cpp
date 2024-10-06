#include <../include/argParser.hpp>

ArgParser::ArgParser(int &argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        tokens.push_back(argv[i]);
    }
}

// Returns the command line option value if it exists
std::optional<std::string_view> ArgParser::getCmdOption(
    std::string_view option) const {
    auto itr = std::find(tokens.begin(), tokens.end(), option);
    if (itr != tokens.end() && ++itr != tokens.end()) {
        return *itr;
    }
    return std::nullopt;  // Indicate no option found
}

// Checks if a command line option exists
bool ArgParser::cmdOptionExists(std::string_view option) const {
    return std::find(tokens.begin(), tokens.end(), option) != tokens.end();
}
