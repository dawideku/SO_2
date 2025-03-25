all: philosophers

philosophers: main.cpp DiningPhilosophers.cpp DiningPhilosophers.h
	g++ -o philosophers main.cpp DiningPhilosophers.cpp -std=c++11 -lpthread

clean:
	rm -f philosophers