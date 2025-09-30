#include <vector>
#include <cmath>

#include <glad/glad.h>

#include "circle.hpp"

Circle::Circle(float x_center, float y_center, float radius) {
    this->radius = radius;
    this->x_center = x_center;
    this->y_center = y_center;

    this->mesh = new Mesh(this->generate_vertices());
};

Circle::~Circle() {
    delete this->mesh;
};

void Circle::draw() {
    this->mesh->draw();
}
std::vector<float> Circle::generate_vertices() {
    std::vector<float> vertices;
    vertices.reserve(3 * N_VERTICES_PER_CIRCLE );

    
    for (int i=0; i<N_VERTICES_PER_CIRCLE ; i++) {
	float angle = 2*M_PI * i / N_VERTICES_PER_CIRCLE ;
	vertices.push_back(radius * std::cos(angle) + x_center);
	vertices.push_back(radius * std::sin(angle) + y_center);
	vertices.push_back(0);
    }
    
    return vertices;
}

