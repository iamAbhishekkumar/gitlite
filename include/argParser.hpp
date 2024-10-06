#ifndef ARGPARSER_H
#define ARGPARSER_H
#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

class ArgParser {
   private:
    std::vector<std::string> tokens;

   public:
    ArgParser(int &argc, char **argv);

    // Returns the command line option value if it exists
    std::optional<std::string_view> getCmdOption(std::string_view option) const;

    // Checks if a command line option exists
    bool cmdOptionExists(std::string_view option) const;
};

#endif