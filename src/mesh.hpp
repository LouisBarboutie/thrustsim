#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

class Mesh 
{
public:
    Mesh(std::vector<float> vertices);
    ~Mesh();
    void draw();

private:
    unsigned int VBO, VAO;
    std::vector<float> vertices;
};

#endif
