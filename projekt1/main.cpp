#include "DiningPhilosophers.h"

using namespace std;

int main() {
    int numPhilosophers;
    cout << "Philosophers amount: ";
    cin >> numPhilosophers;

    DiningPhilosophers dp(numPhilosophers);
    dp.start();

    return 0;
}
