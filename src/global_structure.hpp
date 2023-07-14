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
            "library"};

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
        std::cout << "Default();\n";
        return 0;
    }

    // library config
    int createLibrary()
    {
        std::cout << "Lib();\n";
        return 0;
    }

    // Logic this Command Line Interface floyzcpp
    void logicCLI()
    {
        int use_config;
        std::cout << "Use config: 1) default\n2) library\n Set number: ";
        std::cin >> use_config;

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
            std::string start_msg = "Start floyzcpp generating projects";
            std::cout << start_msg << std::endl;
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