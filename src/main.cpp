#include <iostream>

#include "cluster.hpp"
#include "display.hpp"

int main(void){
    Display* display = new Display();

    int n_engines;
    std::cout << "Enter the number of engines for the cluster: ";
    std::cin >> n_engines;

    Cluster* cluster = new Cluster(n_engines);
    cluster->ignite();

    display->add_cluster(cluster);
    display->render();

    delete cluster;
    delete display;

    return 0;
}
