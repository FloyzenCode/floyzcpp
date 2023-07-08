#include <iostream>
#include <string>
#include <filesystem>
#include <curl/curl.h>

int SendFileToServer(const char* pathToFile)
{
    CURL *curl;
    CURLcode res;

    // Init cURL
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl)
    {
        // Install URL-address for send file
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/upload"); // Change the URL port to your liking

        // open file for read
        FILE *file = fopen(pathToFile, "rb");
        if (!file)
        {
            std::cout << "Not open file" << std::endl;
            return 1;
        }

        // Install parameters for POST-request for send file
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, file);

        // Execution of a request
        res = curl_easy_perform(curl);

        // Error checking
        if (res != CURLE_OK)
        {
            std::cout << "Error send file: " << curl_easy_strerror(res) << std::endl;
        }

        // Close file
        fclose(file);

        // Clear resources cURL
        curl_easy_cleanup(curl);
    }

    // Global clear resources cURL
    curl_global_cleanup();

    return 0;
}

void SearchFile(const std::filesystem::path dir, const std::string filename)
{
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (entry.is_directory())
        {
            SearchFile(entry.path(), filename);
        }
        else if (entry.is_regular_file() && entry.path().filename().string() == filename)
        {
            std::cout << "File succes find: " << entry.path().string() << std::endl;
        }
    }
}

int main()
{
    std::string filename;
    std::cout << "Input file name for search: ";
    std::cin >> filename;

    std::filesystem::path rootDir = "C:\\"; // Change the path if another drive is needed or folder

    SearchFile(rootDir, filename);

    return 0;
}