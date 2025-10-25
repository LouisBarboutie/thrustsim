#include <iostream>
#include <list>
#include <memory>
#include <cmath>

#include "cluster.hpp"
#include "engine.hpp"

Cluster::Cluster() {
    // Outline of the cluster
    this->circles.push_back(new Circle(0.0f, 0.0f, 1.0f));
    this->n_rings = 0;
}


void Cluster::add_central_engine() {
    if (this->has_central_engine) {
	return;
    }
    this->circles.push_back(new Circle(0.0f, 0.0f, 0.1f));
    this->engines.push_back(std::make_unique<Engine>());
    this->has_central_engine = true;
}

void Cluster::add_engine_ring(int n_engines) {
    this->n_rings++;
    float step = 2 * M_PI / n_engines;
    float radius = 0.1; 
    float ring_radius = 0.25 * this->n_rings; 
    float x, y;

    for (int i=0; i<n_engines; i++) {
	x = ring_radius * cos(step * i);
	y = ring_radius * sin(step * i);
	this->circles.push_back(new Circle(x, y, radius));
	this->engines.push_back(std::make_unique<Engine>());
    }

}

void Cluster::ignite() {
    for (std::unique_ptr<Engine>& engine: this->engines) {
	bool ignition_status = engine->ignite();
	std::cout << "Engine: " << &engine << " Ignition: " << ignition_status << std::endl;	
    }
}
