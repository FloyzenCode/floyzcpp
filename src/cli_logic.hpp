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
    void help(const std::string errMesssage)
    {
        std::array<std::string, 6> helpMessage = {
            "|---------------------------------------------------------------|",
            "| 💡 floyzcpp help:                                             |",
            "|---------------------------------------------------------------|",
            "| 🟢 floyzcpp create default - create default structure project |",
            "| 🟢 floyzcpp create library - create library structure project |",
            "|---------------------------------------------------------------|",
        };

        std::cout << "🔴 " << errMesssage << " failed" << std::endl;

        for (const std::string &element : helpMessage)
            std::cout << element << '\n';
    }

    void help()
    {
        std::array<std::string, 6> helpMessage = {
            "|---------------------------------------------------------------|",
            "| 💡 floyzcpp help:                                             |",
            "|---------------------------------------------------------------|",
            "| 🟢 floyzcpp create default - create default structure project |",
            "| 🟢 floyzcpp create library - create library structure project |",
            "|---------------------------------------------------------------|",
        };

        for (const std::string &element : helpMessage)
            std::cout << element << '\n';
    }

    // errors functions
    void error()
    {
        std::cout << "Unknow error\n";
    }

    void errorSyntax(std::string errMessage)
    {
        std::cout << "Error syntax command\n";
        fcpp::help(errMessage);
    }

    bool hasSpaces(const std::string &str)
    {
        return str.find(' ') != std::string::npos;
    }

    // default config
    int createDefault() // fstream / std::filesystem / системные вызовы / что угодно иное
    {
        std::string projectName;
        std::cout << "project name: ";
        std::getline(std::cin, projectName);
        if (hasSpaces(projectName))
        {
            fcpp::error();
            return 1;
        }
        std::cout << "Create " << projectName << " project" << std::endl
                  << "Wait second...";

        // create parent folder
        std::filesystem::create_directory(projectName);

        // create structure project
        std::filesystem::create_directory(projectName + "/include");
        std::cout << "Create include..." << std::endl;
        std::ofstream helloWorldFile(projectName + "/include/helloWorld.hpp");
        helloWorldFile << "#include <iostream>\n"
                       << "\n"
                       << "void helloWorld()\n"
                       << "{\n"
                       << "    std::cout << \"Hello World!\" << std::endl;\n"
                       << "}\n";
        helloWorldFile.close();

        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/src");

        std::ofstream mainFile(projectName + "/src/main.cpp");
        mainFile << "#include \"../include/helloWorld.hpp\"\n"
                 << "\n"
                 << "int main()\n"
                 << "{\n"
                 << "    helloWorld();\n"
                 << "    return 0;\n"
                 << "}";
        mainFile.close();

        std::cout << "Create source..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/docs");
        std::cout << "Create docs..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/lib");
        std::cout << "Create lib..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/test");
        std::cout << "Create test..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/scripts");
        std::cout << "Create scripts..." << std::endl;
        std::ofstream CMakeList(projectName + "/CMakeLists.txt");
        CMakeList << "cmake_minimum_required(VERSION 3.20)";
        CMakeList.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "\nGenerate project done!\n";
        return 0;
    }

    // library config
    int createLibrary() // fstream / std::filesystem / системные вызовы / что угодно иное
    {
        std::string projectName;
        std::cout << "project name: ";
        std::getline(std::cin, projectName);
        if (hasSpaces(projectName))
        {
            fcpp::error();
            return 1;
        }
        std::cout << "Create " << projectName << " project" << std::endl
                  << "Wait second...";

        // create parent folder
        std::filesystem::create_directory(projectName);

        // create structure project
        std::filesystem::create_directory(projectName + "/include");
        std::cout << "Create include..." << std::endl;
        std::ofstream module1(projectName + "/include/helloWorld.hpp");
        module1 << "#include <iostream>\n"
                << "\n"
                << "void helloWorld()\n"
                << "{\n"
                << "    std::cout << \"Hello World!\" << std::endl;\n"
                << "}\n";
        module1.close();

        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/src");

        std::ofstream mainFile(projectName + "/main.cpp");
        mainFile << "#include \"../include/helloWorld.hpp\"\n"
                 << "\n"
                 << "int main()\n"
                 << "{\n"
                 << "    helloWorld();\n"
                 << "    return 0;\n"
                 << "}";
        mainFile.close();

        std::cout << "Create source..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/docs");
        std::cout << "Create docs..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/lib");
        std::ofstream file(projectName + "/lib/file.hpp");
        file << "#include <iostream>\n\n"
             << "int foo() {\n"
             << "    std::cout << \"Example file\";\n"
             << "    return 0;\n"
             << "}";
        std::cout << "Create lib..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/test");
        std::cout << "Create test..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::filesystem::create_directory(projectName + "/scripts");
        std::cout << "Create scripts..." << std::endl;
        std::ofstream CMakeList(projectName + "/CMakeLists.txt");
        CMakeList << "cmake_minimum_required(VERSION 3.20)";
        CMakeList.close();
        std::ofstream readme(projectName + "/README.md");
        readme << "# " << projectName << std::endl
               << "Project description...";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "\nGenerate project done!\n";
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
        else if ((argc > 2 && std::string(argv[1]) == "create") && std::string(argv[2]) == "default")
        {
            fcpp::createDefault();
        }
        else if ((argc > 2 && std::string(argv[1]) == "create") && std::string(argv[2]) == "library")
        {
            fcpp::createDefault();
        }

        else if (argc == 1)
        {
            fcpp::help();
        }
        else
        {
            fcpp::errorSyntax(std::string(argv[1]));
        }
    }
}