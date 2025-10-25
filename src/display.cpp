#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	    glUseProgram(circle->mesh->shader_program);
	    this->transform = glm::mat4(1.0f);
	    this->transform = glm::translate(this->transform, glm::vec3(1.0f, 1.0f, 0.0f));
	    this->transform = glm::rotate(this->transform, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	    this->transform = glm::scale(this->transform, glm::vec3(0.5f, 0.5f, 0.5f));

	    unsigned int shader_id = circle->mesh->shader_program;
	    unsigned int transform_location = glGetUniformLocation(shader_id, "transform");
	    glUniformMatrix4fv(transform_location, 1, GL_FALSE, glm::value_ptr(this->transform));

	    circle->mesh->draw();
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
