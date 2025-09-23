#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>

#define VERTEX_SHADER "src/shader.vert"
#define FRAGMENT_SHADER "src/shader.frag"
#define N_VERTICES_PER_CIRCLE 16

class Circle {
public:
    Circle(float x_center, float y_center, float radius);
    ~Circle();

    void draw();

private:
    uint VBO, VAO, vertex_shader, fragment_shader, shader_program;
    std::vector<float> vertices;

    static std::vector<float> get_circle_vertices(int n_vertices, float radius, float x_center, float y_center);
    static uint load_shader(std::string path, GLenum shader_type);
    static uint create_program(uint vertex_shader, uint fragment_shader);
    static std::string read_shader(const std::string path);
};

#endif

