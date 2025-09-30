#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>
#include "mesh.hpp"

#define N_VERTICES_PER_CIRCLE 16

class Circle {
public:
    Circle(float x_center, float y_center, float radius);
    ~Circle();

    void draw();
    Mesh* mesh;

private:
    float x_center, y_center, radius;

    std::vector<float> generate_vertices();
    static std::vector<float> get_circle_vertices(int n_vertices, float radius, float x_center, float y_center);
};

#endif

