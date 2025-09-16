#include <iostream>
#include "engine.hpp"

Engine::Engine() {}

Engine::~Engine(){}

bool Engine::ignite() {
    float roll = static_cast<float> (std::rand()) / static_cast<float> (RAND_MAX);
    if (roll > this->ignition_probability) {
	return false;
    }

    return true;
}
