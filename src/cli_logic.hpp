/*
        ███████╗██╗░░░░░░█████╗░██╗░░░██╗███████╗░░░░░█████╗░██████╗░██████╗░
        ██╔════╝██║░░░░░██╔══██╗╚██╗░██╔╝╚════██║░░░░██╔══██╗██╔══██╗██╔══██╗
        █████╗░░██║░░░░░██║░░██║░╚████╔╝░░░███╔═╝░░░░██║░░╚═╝██████╔╝██████╔╝
        ██╔══╝░░██║░░░░░██║░░██║░░╚██╔╝░░██╔══╝░░░░░░██║░░██╗██╔═══╝░██╔═══╝░
        ██║░░░░░███████╗╚█████╔╝░░░██║░░░███████╗░░░░╚█████╔╝██║░░░░░██║░░░░░
        ╚═╝░░░░░╚══════╝░╚════╝░░░░╚═╝░░░╚══════╝░░░░░╚════╝░╚═╝░░░░░╚═╝░░░░░
*/

#include <iostream>
#include <string>
#include <array>
#include <chrono>
#include <thread>
#include <filesystem>
#include <fstream>

namespace fcpp
{
    void help(const std::string errMesssage);

    void help();

    // errors functions
    void error();

    void errorSyntax(std::string errMessage);

    bool hasSpaces(const std::string &str);
    // default config
    int createDefault(); // fstream / std::filesystem / системные вызовы / что угодно иное

    // library config
    int createLibrary(); // fstream / std::filesystem / системные вызовы / что угодно иное

    // Logic this Command Line Interface floyzcpp
    void logicCLI();

    // Start function
    void startCLI(int argc, char *argv[]);
}
