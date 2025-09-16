#include <list>
#include <algorithm>
#include <iostream>
#include <memory>
#include "cluster.hpp"
#include "engine.hpp"

Cluster::Cluster(int n_engines) {
    this->engines = std::list<std::unique_ptr<Engine>>{};
    for (size_t i=0; i<n_engines; i++) {
	this->engines.push_back(std::make_unique<Engine>());
    }
    this->n_engines_per_circle.push_back(n_engines);
    this->circle_radii.push_back(1.0);
}

Cluster::~Cluster() {}

void Cluster::add_engine(std::unique_ptr<Engine> engine) {
    this->engines.push_back(std::move(engine));
}

void Cluster::ignite() {

    // std::for_each(this->engines.begin(), this->engines.end(), [](std::unique_ptr<Engine> engine) {
	// bool ignition_status = engine->ignite();
	// std::cout << "Engine: " << engine << " Ignition: " << ignition_status << std::endl;	
    // });
    for (std::unique_ptr<Engine>& engine: this->engines) {
	bool ignition_status = engine->ignite();
	std::cout << "Engine: " << &engine << " Ignition: " << ignition_status << std::endl;	
    }
}
