#ifndef DINING_PHILOSOPHERS_H
#define DINING_PHILOSOPHERS_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <chrono>

class DiningPhilosophers {
private:
    int numPhilosophers;          // Number of philosophers
    std::vector<std::mutex> forks; // Mutex for each fork
    std::vector<std::thread> philosophers; // Threads for philosophers
    std::mt19937 rng;             // Random number generator
    std::mutex coutMutex;           // Mutex for synchronizing console output

    [[noreturn]] void philosopher(int id);      // Function representing a philosopher's behavior
    void think(int id);            // Simulates thinking
    void eat(int id);              // Simulates eating
    int getRandomTime();           // Generates a random time delay

public:
    explicit DiningPhilosophers(int n);     // Constructor
    void start();                  // Starts the simulation
};

#endif
