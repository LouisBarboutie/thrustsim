#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "display.hpp"
#include "circle.hpp"
#include "cluster.hpp"

Display::Display() {
    if (!glfwInit()) {
	std::cout << "GLFW failed to initialize!" << std::endl;
	return;
    }
    std::cout << "GLFW initialized!" << std::endl;

    this->initialize_window();

}
Display::~Display() {};

void Display::initialize_window() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(800, 600, "Thrustsim", nullptr, nullptr);

    if (window == nullptr) {
	const char* description;
	int error = glfwGetError(&description);
	std::cout << "Failed to create GLFW window! Error: " << error << " - " << description << std::endl;
	glfwTerminate();
	return;
    }

    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, this->framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
	std::cout << "GLAD failed to initialize!" << std::endl;
	return;
    }
    std::cout << "GLAD initialized!" << std::endl;

    glViewport(0, 0, 800, 600);
};

void Display::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Display::render() { 
    while (!glfwWindowShouldClose(this->window)) {
	glfwPollEvents();
	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (Circle* circle : this->circles) {
	    circle->draw();
	}
	
	glfwSwapBuffers(window);
    }
}

void Display::add_circle(Circle* circle){
    this->circles.push_back(circle);
}

void Display::add_cluster(Cluster* cluster){
    for (Circle* circle: cluster->circles) {
	this->add_circle(circle);
    }
}
