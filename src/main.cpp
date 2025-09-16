#include <iostream>
#include <memory>

#include "engine.hpp"
#include "cluster.hpp"
#include "render.hpp"

int main(void){

    uint n_engines;    
    std::cout << "Enter the number of engines for the cluster: ";
    std::cin >> n_engines;

    Cluster* cluster = new Cluster(n_engines);
    cluster->ignite();
    delete cluster;

    render();
    createWindow();

    return 0;
}
