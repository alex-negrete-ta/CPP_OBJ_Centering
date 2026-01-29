#pragma once
#include <vector>
#include <string>

using namespace std;

class Mesh
{
public:
    // Setting the functions.
    bool Load(string filename);
    void Center();
    void Save(string filename);

private:
    // Creates geometry data type to store.
    struct Vertex
    {
        float x, y, z;
    };

    struct Face
    {
        vector<int> vertexIndices;
    };

    // Initializesa the objects as vertex type.
    vector<Vertex> vertices;
    vector<Face> faces;
};
