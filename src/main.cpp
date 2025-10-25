#include <cctype>
#include <iostream>
#include <string>
#include <cctype>
#include <array>

#include "cluster.hpp"
#include "display.hpp"

int main(void){
    Display* display = new Display();
    Cluster* cluster = new Cluster();

    int n_engines = 0;
    int n_rings = 0;
    bool add_center_engine = false;
    char response;

    std::cout << "Add a central engine? [Y/N]: ";
    std::cin >> response;
    add_center_engine = std::toupper(response) == 'Y';
    if (add_center_engine) {
	cluster->add_central_engine();
    }

    std::cout << "Enter the number of engine rings: ";
    std::cin >> n_rings;

    for (int i=0; i<n_rings; i++) {
	std::cout << "Enter the number of engines for the ring " << i << ": ";
	std::cin >> n_engines;
	cluster->add_engine_ring(n_engines);
    }

    cluster->ignite();

    display->add_cluster(cluster);
    display->render();

    delete cluster;
    delete display;

    return 0;
}
