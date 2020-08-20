// rdme-gen in cpp

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

using namespace std;

// Functions
void processArgs(int argc, const char *argv[]);
void error_message(string type);
bool pathExists(const string &s);
void determinePaths();
string get_current_dir();
void copyThis(string from, string to);
void copyFile(std::string start, std::string destination);
bool copyFile(string *from, string *to);
bool copyFolder(string *from, string *to);

// Variables
bool img = false;
bool fillable = false;
bool path = false;
bool help = false;

string rdme_gen_folder = string(getenv("HOME")) + "/.rdme-gen";

string rdme_target_path;
string img_target_path;

string rdme_source_path = rdme_gen_folder;
string img_source_path = rdme_gen_folder;

string bad_target_path;


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
    if (rdme_target_path == "" && path)
    {
        printf("The file path \"%s\" does not exist.\n", bad_target_path.c_str());
        return 0;
    }

    // determine paths

    determinePaths();

    // copy

    copyFile(&rdme_source_path, &rdme_target_path);
    if (img)
    {
        copyFolder(&img_source_path, &img_target_path);
    }

    //Debugging
    cout
        << "Images: " << img
        << "\nPath: " << path
        << "\nFillable: " << fillable
        << "\nHelp: " << help
        << "\nREADME.md From: " << rdme_source_path
        << " To: " << rdme_target_path
        << "\nIMGS From: " << img_source_path
        << " To: " << img_target_path << endl;

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
                    rdme_target_path = argv[i + 1];
                img_target_path = rdme_target_path;
            }
            else
                rdme_target_path = "";
        }
    }
}

bool pathExists(const string &s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

void determinePaths()
{
    //Source
    if (img)
    {
        rdme_source_path += "/default-with-images/mainTemplate.md";
        img_source_path += "/default-with-images/rdme-images";
    }
    else
    {
        rdme_source_path += "/default/mainTemplate.md";
        img_source_path = "";
    }

    //Target
    if (!path)
    {
        rdme_target_path = get_current_dir() + "/README.md";
        img_target_path = "";
    }
    else
    {
        rdme_target_path += "/README.md";
        img_target_path += "";
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
    if (type == "HELP")
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
    if (type == "PATH_NOT_FOUND")
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
    string system_string = "cp " + *from + " " + *to;

    system(system_string.c_str());

    return true;
}

bool copyFolder(string *from, string *to)
{
    //string make_folder = "mkdir " + *to;
    string copy_folder = "cp -r " + *from + " " + *to;

    //system(make_folder.c_str());
    system(copy_folder.c_str());

    return true;
}
