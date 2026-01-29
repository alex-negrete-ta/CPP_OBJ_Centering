#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include "../include/Mesh.h"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main()
{
    // Initializes the objects and variables.
    Mesh myObject;
    string filename;
    string outputName;

    // Reads in the users input.
    cout << "Whats the object filename?\n";
    getline(cin, filename);
    // Get the outputline.
    fs::path inputPath(filename);
    // Extract the name, saves the new file name and path.
    string pureFilename = inputPath.filename().string();
    string newFilename = "centered_" + pureFilename;
    fs::path outputPath = inputPath.parent_path() / newFilename;
    string finalOutputName = outputPath.string();

    // Loads in the file and checks if is loaded.
    if (myObject.Load(filename))
    {
        cout << "Loading geometry...\n";

        // Loads the geometry.
        myObject.Load(filename);
        cout << "It has been loaded. \n"
             << "Centering... \n";
    }
    else
    {
        cout << "File could not be loaded.\n";
        return 1;
    }

    // It centers the geometry.
    myObject.Center();
    cout << "It has been centered. \n"
         << "Saving... \n";

    // It saves the centered file.
    myObject.Save(finalOutputName);
    cout << "Finished centering!" << endl;

    // Holds the screen waiting for respond.
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
