#include "../include/Mesh.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

void Mesh::Center()
{
    /*
    Description:
    It centers the loaded geometry by grabbing the bouding box and vertices positions.

    Input:
    None.

    Output:
    None.
    */
    struct BBox
    {
        float minX = INFINITY;
        float maxX = -INFINITY;
        float minY = INFINITY;
        float maxY = -INFINITY;
        float minZ = INFINITY;
        float maxZ = -INFINITY;
    };

    BBox limitBox;

    // We don't read the file here. We just look at the data we already have.
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].x < limitBox.minX)
            limitBox.minX = vertices[i].x;
        if (vertices[i].x > limitBox.maxX)
            limitBox.maxX = vertices[i].x;

        if (vertices[i].y < limitBox.minY)
            limitBox.minY = vertices[i].y;
        if (vertices[i].y > limitBox.maxY)
            limitBox.maxY = vertices[i].y;

        if (vertices[i].z < limitBox.minZ)
            limitBox.minZ = vertices[i].z;
        if (vertices[i].z > limitBox.maxZ)
            limitBox.maxZ = vertices[i].z;
    }

    // Finds the center point of all three axis.
    Vertex centerPoint;
    centerPoint.x = (limitBox.minX + limitBox.maxX) / 2.0;
    centerPoint.y = (limitBox.minY + limitBox.maxY) / 2.0;
    centerPoint.z = (limitBox.minZ + limitBox.maxZ) / 2.0;

    // Centers the vertices.
    for (int i = 0; i < vertices.size(); i++)
    {
        vertices[i].x = vertices[i].x - centerPoint.x;
        cout << vertices[i].x;
        vertices[i].y = vertices[i].y - centerPoint.y;
        cout << vertices[i].y;
        vertices[i].z = vertices[i].z - centerPoint.z;
        cout << vertices[i].z;
    };
}

bool Mesh::Load(string filename)
{
    /*
    Description:
    Loads in the obj geometry to be altered.

    Input:
    filename (string): The object name and extension 'object.obj'.

    Output:
    0/1: True/False if theres is a geometry loaded.
    */
    cout << "Loading " << filename << "..." << endl;

    // Initialize the variables.
    string line = "";
    ifstream myGeo(filename);

    if (!myGeo.is_open())
    {
        cout << "Error: Could not open file! \n";
        return false;
    }

    // Store the object information.
    while (getline(myGeo, line))
    {
        cout << line << endl;
        // Adds the vertex position to an object.
        if (line[0] == 'v')
        {
            // Initializes my letter holder and container.
            cout << "Found vertex";
            Vertex myVertex;
            char type;

            // Separate the values.
            stringstream ss(line);
            cout << "This is the position: " << ss.str();

            // Transfer SS to temp objects, and into a full folder.
            ss >> type >> myVertex.x >> myVertex.y >> myVertex.z;
            vertices.push_back(myVertex);
        }

        // Builds the faces back together.
        else if (line[0] == 'f')
        {
            cout << "Found Face";
            char temp;
            int index;
            stringstream ss(line);
            ss >> temp;
            Face tempFace;
            while (ss >> index)
            {
                tempFace.vertexIndices.push_back(index);
            }
            faces.push_back(tempFace);
        }
    };
    myGeo.close();
    return true;
};

void Mesh::Save(string filename)
{
    /*
    Description:
    Saves the geometry out into a new file centered.

    Input:
    filename (str) : String of the filename you want to use.

    Output:
    None
    */

    // Writes a new file with the centered vertices and faces.
    ofstream newFile(filename);
    for (int i = 0; i < vertices.size(); i++)
    {
        newFile << "v " << vertices[i].x << " " << vertices[i].y
                << " " << vertices[i].z << endl;
    }

    for (int i = 0; i < faces.size(); i++)
    {
        newFile << "f ";
        // Writes the faces into the new file.
        for (int j = 0; j < faces[i].vertexIndices.size(); j++)
        {
            newFile << " " << faces[i].vertexIndices[j];
        }
        newFile << endl;
    }
};