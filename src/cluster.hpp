#ifndef CLUSTER_HPP
#define CLUSTER_HPP

#include <list>
#include <memory>

#include "engine.hpp"
#include "circle.hpp"

class Cluster {

public:
    Cluster();
    void add_central_engine();
    void add_engine_ring(int n_engines);
    void ignite();
    std::list<Circle*> circles;

private:
    std::list<std::unique_ptr<Engine>> engines;
    bool has_central_engine = false;
    int n_circles;
    int n_rings;
};

#endif

