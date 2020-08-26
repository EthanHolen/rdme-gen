#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <vector>

using namespace std;

void fill_out();


int main(int argc, char const *argv[])
{
    fill_out();
    return 0;
}




void fill_out()
{
    vector<string> search;
    vector<string> replace;
    search.push_back("github_username");
    search.push_back("repo");
    search.push_back("twitter_handle");
    search.push_back("email");

    for (int i = 0; i < search.size(); i++)
    {
        string temp;
        cout << search[i] << ":";
        cin >> temp;
        replace.push_back(temp);
    }
    cout << "\n";

    for (int i = 0; i < replace.size(); i++)
    {
        cout << search[i] << " = " << replace[i] << "\n";
    }



}
