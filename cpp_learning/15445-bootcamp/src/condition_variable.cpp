/**
 * @file condition_variable.cpp
 * @author Abigale Kim (abigalek)
 * @brief Tutorial code for C++ STL condition variable.
 */

// This program shows a small example of the usage of std::condition_variable.
// The std::condition_variable class provides the condition variable
// synchronization primitive. The condition variable primitive allows threads
// to wait until a particular condition before they grab a mutex. It also
// allows other threads to signal waiting threads to alert them that
// the condition may be true.

// For a more detailed introduction of C style condition variables, see
// https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf.

// Note: lock have mutex vs spin lock
// A semaphore is a nonnegative integer along with two atomic operators for
//    manipulating it:
//   - down or "P": wait for the value to become positive, then
//      decrement it.
//      - when lock_acquire, it will call semaphore_down to wait for available lock
//   - up or "V": increment the value (and wake up one waiting
//      thread, if any).
//     - when lock_release, it will call semaphore_up to release the lock

// This program runs three threads. Two of these threads run a function that
// increments a global count variable by 1, atomically, and notifies the
// waiting thread when the count variable is 2. When the count variable is
// 2, the waiting thread wakes up, acquires the lock, and prints the count
// value.

// Includes the condition variable library header.
#include <condition_variable>
// Includes std::cout (printing) for demo purposes.
#include <iostream>
// Includes the mutex library header.
#include <mutex>
// Includes the thread library header.
#include <thread>

// Note: RAII
// RAII stands for Resource Acquisition Is Initialization. It's a programming idiom used in C++ (and sometimes in other
// languages) for managing resources like memory or file handles. The basic idea is to tie the lifetime of resources to
// the lifetime of objects that manage them. When an object is created, it acquires the resource, and when it's
// destroyed (usually when it goes out of scope), the resource is automatically released.

// Defining a global count variable, a mutex, and a condition variable to
// be used by both threads.
int count = 0;
std::mutex m;

// This is the syntax for declaring and default initializing a condition
// variable.
std::condition_variable cv;

// In this function, a thread increments the count variable by
// 1. It also will notify one waiting thread if the count value is 2.
// It is ran by two of the threads in the main function.
void add_count_and_notify() {
  // Note: introduced in c++17, scoped_lock: When managing a single mutex, std::scoped_lock locks
  // the mutex upon construction and unlocks it upon destruction.
  // Critical section protected by mtx (in the function scope)
  std::scoped_lock slk(m);

  count += 1;
  if (count == 2) {
    cv.notify_one();
  }
}
// mtx is automatically released here

// This function, ran by the waiting thread, waits on the condition
// count == 2. After that, it grabs the mutex m and executes code in
// the critical section.
// Condition variables need an std::unique_lock object to be constructed.
// std::unique_lock is a type of C++ STL synchronization primitive that
// gives more flexibility and features, including the usage with
// condition variables. Particularly, it is moveable but not copy-constructible
// or copy-assignable.
void waiter_thread() {
  // Note: unique_lock
  // mutex wrapper that provides a unique ownership model
  // Condition Variable Support: It can be used with condition variables (std::condition_variable). A std::unique_lock
  // object can be passed to the wait, wait_for, or wait_until methods of a condition variable, allowing the thread to
  // block until notified and the condition is satisfied.
  std::unique_lock lk(m);
  // wait will end only when count == 2
  cv.wait(lk, [] { return count == 2; });

  std::cout << "Printing count: " << count << std::endl;
}

// The main method constructs three thread objects and has two of them run the
// add_count_and_notify function in parallel. After these threads are finished
// executing, we print the count value, from the waiter thread, showing that
// both increments, along with the conditional acquisition in the waiter
// thread, worked successfully.
int main() {
  // Initializes three threads (t1, t2, t3), with t1 and t2 running add_count_and_notify and t3 running waiter_thread.
  // Calls join() on each thread to ensure the main thread waits for all threads to complete their execution before
  // exiting.
  std::thread t1(add_count_and_notify);
  std::thread t2(add_count_and_notify);
  std::thread t3(waiter_thread);
  t1.join();
  t2.join();
  t3.join();
  // t1 and t2 increment count in a thread-safe manner. Once count reaches 2, cv.notify_one() wakes up t3. 
  // t3 prints the count value, demonstrating successful synchronization between threads.
  return 0;
}