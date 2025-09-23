#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <list>

#include "circle.hpp"

class Display {

public:
    Display();
    ~Display();
    void render();
    void add_circle();

private:
    GLFWwindow* window;

    void initialize_window();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    std::list<Circle*> circles;
};

#endif
