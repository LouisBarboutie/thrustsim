#ifndef CLUSTER_HPP
#define CLUSTER_HPP

#include <list>
#include <memory>
#include "engine.hpp"

class Cluster {

public:
    Cluster(int n_engines);
    ~Cluster();
    void add_engine(std::unique_ptr<Engine> engine);
    void ignite();

private:
    std::list<std::unique_ptr<Engine>> engines;
    int n_circles;
    std::list<int> n_engines_per_circle;
    std::list<float> circle_radii;
};

#endif
