// rdme-gen in cpp

#include <iostream>
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
bool pathExists(const string &s);
void determinePaths(string *rdme_path, string *img_path);
string get_current_dir();





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


    determinePaths(&rdme_path, &img_path);
    


    target_path = get_current_dir();

    // copy




    // Debugging
    cout
        << "last argument: " << argv[argc - 1] << endl
        << "Images: " << img << endl
        << "rdme_gen_folder: " << rdme_gen_folder << endl
        << "rdme_path: " << rdme_path << endl
        << "img_path: " << img_path << endl
        << "Path: " << path << endl
        << "Target Path: " << target_path << endl
        << "Fillable: " << fillable << endl 
        << "Help: " << help << endl;


    return 1;
}


void processArgs(int argc, const char *argv[])
{
    for (int i = 0; i < argc; i++)
    {

        string argument = string(argv[i]);

        if (argument == "-h" || argument == "--help")
        {
            cout << "HELP MESSAGE" << endl;
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



void determinePaths(string *rdme_path, string *img_path)
{

    if (img)
    {
        *rdme_path += "/default-with-images/mainTemplate.md";
        *img_path += "//default-with-images/rdme-images";
    }
    else
    {
        /* code */
    }
    
}



string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   getcwd( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}