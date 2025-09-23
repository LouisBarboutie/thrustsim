#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>

#include <glad/glad.h>

#include "circle.hpp"

Circle::Circle(float x_center, float y_center, float radius) {
    this->vertex_shader = load_shader(VERTEX_SHADER, GL_VERTEX_SHADER);
    this->fragment_shader = load_shader(FRAGMENT_SHADER, GL_FRAGMENT_SHADER);
    this->shader_program = create_program(vertex_shader, fragment_shader);
    
    glDeleteShader(this->vertex_shader);
    glDeleteShader(this->fragment_shader);
	
    this->vertices = get_circle_vertices(N_VERTICES_PER_CIRCLE, radius, x_center, y_center);
    glGenVertexArrays(1, &(this->VAO));
    glGenBuffers(1, &(this->VBO));
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(float), this->vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
};

Circle::~Circle() {};

void Circle::draw() {
    glUseProgram(this->shader_program);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_LINE_LOOP, 0, N_VERTICES_PER_CIRCLE);
}

std::vector<float> Circle::get_circle_vertices(int n_vertices, float radius, float x_center, float y_center) {
    std::vector<float> vertices;
    std::cout << "Number of elements in the vector: " << 3*n_vertices << std::endl;
    vertices.reserve(3 * n_vertices);

    
    for (int i=0; i<n_vertices; i++) {
	float angle = 2*M_PI * i / n_vertices;
	vertices.push_back(radius * std::cos(angle) + x_center);
	vertices.push_back(radius * std::sin(angle) + y_center);
	vertices.push_back(0);
    }
    
    return vertices;
}

std::string Circle::read_shader(const std::string path) {
    std::ifstream stream;
    std::string line;
    std::stringstream shader;

    stream.open(path);

    if (!stream.is_open()) {
	std::cout << "Error while opening the file: " << path << std::endl;
	std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    }

    while (std::getline(stream, line)) {
	shader << line << "\n";
    }
    stream.close();

    return shader.str();
}

uint Circle::load_shader(std::string path, GLenum shader_type) {
    std::string shader_contents = read_shader(path);
    const char* shader_code = shader_contents.c_str();
    
    uint shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_code, nullptr);
    glCompileShader(shader);

    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, info_log);
	std::cout << "Compilation of the shader of type: " << shader_type << " failed!\n" << info_log << std::endl;
    }

    return shader;
}

uint Circle::create_program(uint vertex_shader, uint fragment_shader) {
    uint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    int success;
    char info_log[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
	glGetProgramInfoLog(program, 512, nullptr, info_log);
	std::cout << "Linking of the program failed: \n" << info_log << std::endl;
    }

    return program;
}

