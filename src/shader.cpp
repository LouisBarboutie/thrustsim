#include "shader.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>

Shader::Shader(const std::filesystem::path& vertex_shader, const std::filesystem::path& fragment_shader) 
{
    this->vertex_shader_id = load_shader(vertex_shader, GL_VERTEX_SHADER);
    this->fragment_shader_id = load_shader(fragment_shader, GL_FRAGMENT_SHADER);
    this->create_program();
}

void Shader::use()
{
    glUseProgram(this->program_id);
}    

unsigned int Shader::id() 
{
    return this->program_id;
}

std::string Shader::read_shader(const std::filesystem::path path) 
{
    std::ifstream stream { path };
    std::string contents {""};
    std::string line {};

    if (!stream.is_open()) 
    {
	std::cout << "Error while opening the file: " << path << std::endl;
	std::cout << std::filesystem::current_path() << std::endl;
    }

    while (std::getline(stream, line)) 
    {
	contents += line + '\n';
    }


    return contents;
}

unsigned int Shader::load_shader(const std::filesystem::path path, const GLenum type) 
{
    std::string shader_contents = Shader::read_shader(path);
    const char* shader_source = shader_contents.c_str();

    unsigned int shader_id = glCreateShader(type);
    if (shader_id == 0) 
	std::cout << "Shader creation failed!" << std::endl; 
    glShaderSource(shader_id, 1, &shader_source, nullptr);
    glCompileShader(shader_id);

    int success;
    const int log_size = 512;
    char info_log[log_size];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
	glGetShaderInfoLog(shader_id, log_size, nullptr, info_log);
	std::cout << "Compilation of the shader of type: " << type << " failed!\n" << info_log << std::endl;
    }
    else 
	std::cout << "Compilation of the shader of type: " << type << " succeeded!" << std::endl;

    return shader_id;
}

void Shader::create_program() 
{
    this->program_id = glCreateProgram();
    glAttachShader(this->program_id, this->vertex_shader_id);
    glAttachShader(this->program_id, this->fragment_shader_id);
    glLinkProgram(program_id);
    glDeleteShader(this->vertex_shader_id);
    glDeleteShader(this->fragment_shader_id);

    int success;
    const int log_size = 512;
    char info_log[log_size];
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (!success) 
    {
	glGetProgramInfoLog(program_id, log_size, nullptr, info_log);
	std::cout << "Linking of the program failed: \n" << info_log << std::endl;
    }
    else 
	std::cout << "Linking of the program succeeded!" << std::endl;
}
