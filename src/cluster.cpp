#include <iostream>
#include <list>
#include <memory>
#include <cmath>

#include "cluster.hpp"
#include "engine.hpp"

Cluster::Cluster(int n_engines) {
    this->n_circles = n_engines;
    this->engines = std::list<std::unique_ptr<Engine>>{};
    for (size_t i=0; i<n_engines; i++) {
	this->engines.push_back(std::make_unique<Engine>());
    }

    this->circles.push_back(new Circle(0.0f, 0.0f, 1.0f));
    float step = 2 * M_PI / n_engines;
    float x, y;
    float radius = 0.25;
    for (int i=0; i<n_engines; i++) {
	x = 0.5 * cos(step * i);
	y = 0.5 * sin(step * i);
	this->circles.push_back(new Circle(x, y, radius));
    }
}

Cluster::~Cluster() {}

void Cluster::ignite() {
    for (std::unique_ptr<Engine>& engine: this->engines) {
	bool ignition_status = engine->ignite();
	std::cout << "Engine: " << &engine << " Ignition: " << ignition_status << std::endl;	
    }
}
