#ifndef CLUSTER_HPP
#define CLUSTER_HPP

#include <list>
#include <memory>

#include "engine.hpp"
#include "circle.hpp"
#include "mesh.hpp"

class Cluster {

public:
    Cluster(int n_engines);
    ~Cluster();
    void ignite();
    std::list<Circle*> circles;

private:
    std::list<std::unique_ptr<Engine>> engines;
    int n_circles;
};

#endif
