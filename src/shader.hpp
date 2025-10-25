#ifndef SHADER_HPP
#define SHADER_HPP

#include <filesystem>
#include <string>

#include "glad/glad.h"

class Shader 
{
public:
    Shader(const std::filesystem::path& vertex_shader, const std::filesystem::path& fragment_shader);
    void use();
    unsigned int id();

private:
    unsigned int vertex_shader_id;
    unsigned int fragment_shader_id;
    unsigned int program_id;

    static std::string read_shader(const std::filesystem::path path);
    static unsigned int load_shader(const std::filesystem::path path, const GLenum type);
    void create_program();
};

#endif 
