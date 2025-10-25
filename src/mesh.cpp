#include "mesh.hpp"

#include <vector>

Mesh::Mesh(std::vector<float> vertices) 
{
    this->vertices = vertices;
    glGenVertexArrays(1, &(this->VAO));
    glGenBuffers(1, &(this->VBO));
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(float), this->vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh() {}

void Mesh::draw() {
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_LINE_LOOP, 0, this->vertices.size() / 3);
}

