#ifndef MESH_HPP
#define MESH_HPP

#define VERTEX_SHADER "src/shader.vert"
#define FRAGMENT_SHADER "src/shader.frag"

#include <vector>
#include <string>

#include <glad/glad.h>

class Mesh {
public:
    Mesh(std::vector<float> vertices);
    ~Mesh();
    void draw();
    unsigned int VBO, VAO, vertex_shader, fragment_shader, shader_program;
    std::vector<float> vertices;

private:

    static unsigned int load_shader(std::string path, GLenum shader_type);
    static unsigned int create_program(uint vertex_shader, uint fragment_shader);
    static std::string read_shader(const std::string path);
};

#endif
