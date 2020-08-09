// rdme-gen in cpp

#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/stat.h>

using namespace std;

// Variables
bool img = false;
bool fillable = false;
bool path = false;
bool help = false;
string targetPath;

void processArgs(int argc, const char *argv[]);
bool pathExists(const string &s);







int main(int argc, const char *argv[])
{


    // Parse arguments
    processArgs(argc, argv);
    // only present help message when -h is passed and dont run the rest of the function
    if (help)
        return 0;
    if (!pathExists(targetPath) && path)
    {
        printf("The file path %s does not exist", targetPath.c_str());
        return 0;
    }



    // determine paths




    // copy




    // Debugging
    cout
        << "Images: " << img << endl
        << "Path: " << path << endl
        << "Target Path: " << targetPath << endl
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
            //TODO: fix this so it dosent segfault and says "you did not provide a path"
            targetPath = string(argv[i + 1]);
        }

    }


}


bool pathExists(const string &s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}