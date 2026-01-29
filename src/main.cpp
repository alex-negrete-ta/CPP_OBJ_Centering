#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include "../include/Mesh.h"

using namespace std;

int main()
{
    // Initializes the objects and variables.
    Mesh myObject;
    string filename;
    string outputName;

    // Reads in the users input.
    cout << "Whats the object filename?\n";
    getline(cin, filename);
    outputName = "centered_" + filename;

    // Loads in the file and checks if is loaded.
    if (myObject.Load(filename))
    {
        cout << "Loading geometry...\n";
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
    myObject.Save(outputName);
    cout << "Finished centering!" << endl;

    // Holds the screen waiting for respond.
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
