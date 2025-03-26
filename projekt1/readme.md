# Dining Philosophers Problem

##  Problem Description  
The **Dining Philosophers Problem** is a classic **synchronization problem** in computer science.  
It involves **N philosophers** who alternate between **thinking** and **eating**.  
Each philosopher **needs two forks** to eat, but forks are **shared** with their neighbors.

 **The Issue:**  
If all philosophers try to pick up their **left fork first**, they might get stuck waiting for the right fork, leading to **deadlock**.

---

##  Threads and Their Roles  
In this program, **each philosopher is represented as a separate thread**:  
- `std::thread philosopherThread(i)`  Represents philosopher `i`  
- The thread continuously performs these **three actions** in a loop:  
  1. **Thinking** (`think(id)`)  
  2. **Picking up forks** (mutex-controlled `forks[]`)  
  3. **Eating** (`eat(id)`)  
  4. **Putting down forks**  

---

##  Critical Sections and Synchronization  
**Critical sections** are parts of the code where multiple threads access **shared resources** (e.g., forks, console output).

### **Critical Sections in This Code:**  
**Shared Forks (`forks[]`)**  
   - Each philosopher locks two mutexes before eating.  
   - This prevents two philosophers from using the **same fork simultaneously**.  

**Console Output (`std::cout`)**  
   - Without synchronization, printed messages may **overlap and become unreadable**.  
   - **Solution:** `std::lock_guard<std::mutex> lock(coutMutex);` ensures thread-safe printing.  

### **How Is the Problem Solved?**  
**Mutexes (`std::mutex`)**  Synchronize access to shared resources.  
**Changing the fork-picking order for the last philosopher**  
   - Philosophers **normally pick up the left fork first**, then the right.  
   - The **last philosopher does the opposite** (right fork first, then left).  
   - **Prevents deadlock!** 

---

## How to Run the Project  

### **Clone the Repository**  
```sh
git clone <repo_url>
cd <project_folder>
```
### **Compilation Linux/macOS**  
```sh
g++ -o philosophers main.cpp DiningPhilosophers.cpp -std=c++11 -lpthread
```
### **Run the program**  
```sh
./philosophers 5
```
### **Compilation Windows**  
```sh
g++ -o philosophers.exe main.cpp DiningPhilosophers.cpp -std=c++11 -lpthread
```
### **To run**  
```sh
philosophers.exe 5
```