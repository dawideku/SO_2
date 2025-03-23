#include "DiningPhilosophers.h"

DiningPhilosophers::DiningPhilosophers(int n) : numPhilosophers(n), forks(n), rng(std::random_device{}()) {}

// Generates a random time between 400 and 800 milliseconds
int DiningPhilosophers::getRandomTime() {
    std::uniform_int_distribution<int> dist(400, 800);
    return dist(rng);
}

// Function representing a philosopher's behavior
[[noreturn]] void DiningPhilosophers::philosopher(int id) {
    int leftFork = id;
    int rightFork = (id + 1) % numPhilosophers;

    while (true) {
        think(id);

        // Avoid deadlock: the last philosopher picks up forks in the opposite order
        if (id == numPhilosophers - 1) {
            forks[rightFork].lock();
            forks[leftFork].lock();
        } else {
            forks[leftFork].lock();
            forks[rightFork].lock();
        }

        eat(id);

        // Release forks after eating
        forks[leftFork].unlock();
        forks[rightFork].unlock();
    }
}

void DiningPhilosophers::think(int id) {
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Philosopher " << id << " is thinking" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(getRandomTime()));
}

void DiningPhilosophers::eat(int id) {
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Philosopher " << id << " is eating" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(getRandomTime()));
}

// Starts the philosopher threads
void DiningPhilosophers::start() {
    for (int i = 0; i < numPhilosophers; i++) {
        philosophers.emplace_back(&DiningPhilosophers::philosopher, this, i);
    }
    for (auto& p : philosophers) {
        p.join();
    }
}
