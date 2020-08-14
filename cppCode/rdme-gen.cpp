// rdme-gen in cpp

#include <iostream>
#include <copyfile.h>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

using namespace std;

// Variables
bool img = false;
bool fillable = false;
bool path = false;
bool help = false;
string target_path;
string bad_target_path;
string rdme_gen_folder = string(getenv("HOME")) + "./rdme-gen";

void processArgs(int argc, const char *argv[]);
void help_message(int argc, const char *argv[]);
bool pathExists(const string &s);
void determinePaths(string *rdme_path, string *img_path, string *target_path);
string get_current_dir();
void copyThis(string from, string to);

int main(int argc, const char *argv[])
{

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

    copyThis(rdme_path, target_path);
    // copyfile(rdme_path.c_str(), target_path.c_str(), NULL, COPYFILE_DATA);

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
            help_message(argc, argv);
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
        *img_path += "//default-with-images/rdme-images";
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

void help_message(int argc, const char *argv[])
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

    // usage: rdme-gen [-h] [-img] [-f] [-p]

    // Generate README in current directory.

    // optional arguments:
    //   -h, --help            show this help message and exit
    //   -p , --path           Specify a path for the README other than the
    //                         current directory

    //   -img, --includeImages
    //                         Generate the readme with images
    //   -f, --fill            Prompt for README info to fill automatically";
}

void copyThis(string from, string to)
{
    ifstream in(from.c_str());
    ofstream out(to.c_str());
    string s;
    while(getline(in, s))
        out << s << "\n";

    // dst << src.rdbuf();
}
