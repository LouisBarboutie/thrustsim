#include <iostream>

#include "cluster.hpp"
#include "display.hpp"

int main(void){

    uint n_engines;    
    std::cout << "Enter the number of engines for the cluster: ";
    std::cin >> n_engines;

    Cluster* cluster = new Cluster(n_engines);
    cluster->ignite();
    delete cluster;

    Display* display = new Display();
    display->add_circle();	
    display->render();
    return 0;
}
