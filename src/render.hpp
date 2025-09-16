#ifndef RENDER_HPP
#define RENDER_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void render() {
    std::cout << "Render call!" << std::endl;
    return;
}

void createWindow() {
    if (!glfwInit()) {
	std::cout << "GLFW failed to initialize" << std::endl;
    }
    std::cout << "GLFW init success!" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Thrustsim", nullptr, nullptr);
    if (window == nullptr) {
	const char* description;
	int error = glfwGetError(&description);
	std::cout << "Failed to create GLFW window! Error: " << error << " - " << description << std::endl;
	glfwTerminate();
	return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
	std::cout << "Failed to initialize GLAD" << std::endl;
	return;
    }

    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window)) {
	glfwSwapBuffers(window);
	glfwPollEvents();
    }
}	

#endif
