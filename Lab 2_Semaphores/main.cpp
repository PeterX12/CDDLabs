/*!
    Author: Peter Lucan
    Student Number: C00228946
    Date: 03/11/2020
    Name :Lab Two - Signalling with Semaphores
    Decription: Uses a Semaphore which ensures that one thread finished it's actions beore another thread can begin.
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \class Signal
    \brief An Implementation of Threads Using Semaphores

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions

*/
/*! This method will sleep for the specified length of time and then print "I must print first". It does this thanks to the last line. When thread on get's to the end it signal and Thread 2 can proceed.
*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
/*! displays a message second. When thread 2 reached the first line it will find the value 0. It will then wait for for this value to change. This means that taskTwo cannot execute before taskOne signals*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
