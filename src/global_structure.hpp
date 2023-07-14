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

namespace fcpp
{
    /*
        help function
        CLI arguments: floyzcpp, floyzcpp --help, floyzcpp -h
    */
    void help()
    {
        std::array<std::string, 5> helpMessage = {
            "\nfloyzcpp commands help:\n_________________________",
            "floyzcpp create <type> <name>",
            "<type> arguments:",
            "default",
            "library",
        };

        for (const std::string &element : helpMessage)
            std::cout << element << '\n';
    }
    // errors functions
    void error()
    {
        std::cout << "Unknow error\n";
    }

    void errorSyntax()
    {
        std::cout << "Error syntax command\n";
        fcpp::help();
    }

    // default config
    int createDefault()
    {
        std::string projectName;
        std::cout << "project name: ";
        std::getline(std::cin, projectName);

        std::cout << "Create " << projectName << " project" << std::endl
                  << "Wait second...";

        system(("mkdir " + projectName).c_str()); // create project folder

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "\nFolder - done!\n";

        system(("cd " + projectName).c_str());
        system(("echo \"SSS\" >> ads.txt"));
        return 0;
    }

    // library config
    int createLibrary()
    {
        std::string projectName;
        std::cout << "project name: ";
        std::getline(std::cin, projectName);

        std::cout << "Create " << projectName << " project" << std::endl
                  << "Wait second...";

        system(("mkdir " + projectName).c_str());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "\nFolder - done!\n";
        return 0;
    }

    // Logic this Command Line Interface floyzcpp
    void logicCLI()
    {
        int use_config;
        std::cout << "Use config:\n 1) default\n2) library\nSet number: ";
        std::cin >> use_config;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the input buffer

        if (use_config == 1)
        {
            fcpp::createDefault();
        }
        else if (use_config == 2)
        {
            fcpp::createLibrary();
        }
        else
        {
            fcpp::error();
        }
    }

    // Start function
    void startCLI(int argc, char *argv[])
    {
        if (argc > 1 && std::string(argv[1]) == "create")
        {
            std::cout << "Start floyzcpp generating projects" << std::endl;
            fcpp::logicCLI();
        }
        else if (argc == 1)
        {
            fcpp::help();
        }
        else
        {
            fcpp::errorSyntax();
        }
    }
}

/*
    floyzcpp afd
        Error syntax command - False
        help()

    floyzcpp create default project1
        logicCLI return 0; - Succesfull
*/