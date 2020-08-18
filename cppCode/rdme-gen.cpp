// rdme-gen in cpp

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
// #include <filesystem>
// #include <exception>

using namespace std;

// Variables
bool img = false;
bool fillable = false;
bool path = false;
bool help = false;
string target_path;
string bad_target_path;
string rdme_gen_folder = string(getenv("HOME")) + "/.rdme-gen";

void processArgs(int argc, const char *argv[]);
void error_message(string type);
bool pathExists(const string &s);
void determinePaths(string *rdme_path, string *img_path, string *target_path);
string get_current_dir();
void copyThis(string from, string to);
void copyFile(std::string start, std::string destination);
bool copyFile(string *from, string *to);
bool copyFolder(string *from, string *to);




int main(int argc, const char *argv[])
{
    // check if rdme path exists
    if (!pathExists(rdme_gen_folder))
    {
        error_message("PATH_NOT_FOUND");
        return 0;
    }
    

    // Parse arguments
    processArgs(argc, argv);
    // only present help message when -h is passed and dont run the rest of the function
    if (help)
        return 0;
    if (target_path == "" && path)
    {
        printf("The file path \"%s\" does not exist.\n", bad_target_path.c_str());
        return 0;
    }

    


    // determine paths

    string rdme_path = rdme_gen_folder;
    string img_path = rdme_gen_folder;

    determinePaths(&rdme_path, &img_path, &target_path);

    // copy

    copyFile(&rdme_path, &target_path);
    // if (img)
    // {
    //     copyFolder(&img_path, &target_path)
    // }
    

    // Debugging
    cout
        << "Images: " << img
        << "\nPath: " << path
        << "\nFillable: " << fillable
        << "\nHelp: " << help
        << "\n\nrdme_gen_folder: " << rdme_gen_folder
        << "\nrdme_path: " << rdme_path
        << "\nimg_path: " << img_path
        << "\nTarget Path: " << target_path << endl;

    return 1;
}

void processArgs(int argc, const char *argv[])
{
    for (int i = 0; i < argc; i++)
    {

        string argument = string(argv[i]);

        if (argument == "-h" || argument == "--help")
        {
            error_message("HELP");
            help = true;
        }
        else if (argument == "-img" || argument == "--image")
            img = true;

        else if (argument == "-f" || argument == "--fill")
            fillable = true;

        else if (argument == "-p" || argument == "--path")
        {
            path = true;

            if (string(argv[argc - 1]) != "-p" && string(argv[argc - 1]) != "--path")
            {
                bad_target_path = argv[i + 1];

                if (pathExists(string(argv[i + 1])))
                    target_path = argv[i + 1];
            }
            else
                target_path = "";
        }
    }
}

bool pathExists(const string &s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

void determinePaths(string *rdme_path, string *img_path, string *target_path)
{

    if (img)
    {
        *rdme_path += "/default-with-images/mainTemplate.md";
        *img_path += "/default-with-images/rdme-images";
    }
    else
    {
        *rdme_path += "/default/mainTemplate.md";
        *img_path = "";
    }

    if (!path)
    {
        *target_path = get_current_dir() + "/README.md";
    }
    else
    {
        *target_path += "/README.md";
    }
}

string get_current_dir()
{
    char buff[FILENAME_MAX]; //create string buffer to hold path
    getcwd(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}

void error_message(string type)
{
    if(type == "HELP")
    {
        cout
        << "usage: rdme-gen [-h] [-img] [-f] [-p]\n\n"
        << "Generate README in current directory.\n\n"
        << "optional arguments:\n"
        << "   -h, --help\n"
        << "   -p , --path           Specify a path for the README other than the current directory\n"
        << "   -img, --includeImages  Generate the readme with images\n"
        << "   -f, --fill            Prompt for README info to fill automatically\n";
        // << "   -fd, --fillDefaults   Prompt for info to set as defaults\n"
    }
    if(type == "PATH_NOT_FOUND")
    {
        cout
        << "You do not currently have the path: ~/.readmeTemplates/default\n"
        << "you can quickly add the path by running:\n\n"
        << "git clone https://github.com/EthanHolen/readmeTemplates && mv readmeTemplates ~/.rdme-gen"
        << endl;
    }

}

bool copyFile(string *from, string *to)
{
    string systemString = "cp " + *from + " " + *to;

    system(systemString.c_str());

    return true;

}

bool copyFolder(string *from, string *to)
{
    string systemString = "cp -r " + *from + " " + *to;

    system(systemString.c_str());

    return true;

}