
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>
#include <string>

using namespace std;

static int getRndTimeout() {
    return 1000 * ( 1 + rand() % 10 );
}

mutex mtx;

static void out(string msg) {
    lock_guard<mutex> lock(mtx);
    cout << msg << "\n";
}

void myWorkerFunction(int i, int ms) {

    /*
    mtx.lock();
    cout << "Worker " << i << " ready to work!\n";
    mtx.unlock();
    */
    out("Worker " + to_string(i) + " ready to work!");
    
    // We simulate work that takes some time
    this_thread::sleep_for(chrono::milliseconds(ms));

    /*
    mtx.lock();
    cout << "Worker " << i << " ready to go home!\n";
    mtx.unlock();
    */
    out("Worker " + to_string(i) + " ready to go home!");
}

void basic_thread_management() {
    thread t(myWorkerFunction, 1, 2325);
    cout << "In between!\n";
    t.join();
    cout << "Closing!\n";
}

void many_threads() {
    vector<thread> threads;
    cout << "Starting workers\n";

    for (int i=0;i<10;i++) {
        //thread t(myWorkerFunction, i+1, getRndTimeout());
        threads.emplace_back(myWorkerFunction, i+1, getRndTimeout());    
    }

    cout << "Workers started\n";

    cout << "Waiting for workers to complete\n";
    for (auto& t: threads) {
        t.join();
    }
    cout << "Workers done!\n";
}


int unsafe_counter = 0;
atomic<int> safe_counter(0);

void increment() {
    for (int i=0;i<1000000;i++) {
        unsafe_counter++;
        safe_counter++; // += 1;
    }
}


void counter_example() {
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);

    t1.join();
    t2.join();
    t3.join();

    cout << "Unsafe counter: " << unsafe_counter << "\n";
    cout << "Unsafe counter: " << safe_counter << "\n";
}


int main(int argc, char* argv[])
{
    srand(time(nullptr));
    
    //basic_thread_management();
    //many_threads();
    counter_example();
    
    return 0;
}
