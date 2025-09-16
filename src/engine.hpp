#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine {
public:
    Engine();
    ~Engine();
    bool ignite();
private:
    float ignition_probability = 0.6;
    float thrust = 1000; // in Newton
    float thrust_direction;
};

#endif
