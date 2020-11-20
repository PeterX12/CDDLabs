/*
  This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
/*! \mainpage Lab 5 - Reusable Barriers
 * \author Peter Lucan, 4th Year Software Development student at IT Carlow,C00228946, c00228956@itcarlow.ie
 * \date 20/12/2020
 * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
 * \section desc_sec Decription
 *
 * Description: This is the fifth lab. This lab uses Semaphores to create a reusable barrier. THe barrier also know as a turnstile locks itself after all the threads have passed through it. A reusable barrier is used to synchronize threads that work together performing a series of steps in a loop.
 *
 *
 * \section dep_Sec Dependencies
 * gcc v 7.5.0 or greater
 Make
 *
 * \section install_sec Installation
 * run "make ALL in directory with code."
 *
 *
 *
 */
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 10;
int sharedVariable=0;

/*! \fn barrierTask
    \brief An example of using a reusable barrier
*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
/**
 * The barrierTask function
 *
 * This fucntion implements a reusable barrier. A specified number of threads prints
 * A and the idex of the for loop and B and the idex of the for loop. The Barrier
 * ensures that they print in order. ie. All A0's print first followed by B0's then
 * A1's and B1's and so on. All the threads execute at the first part of the for loop
 * before theBarrier->PhaseOnene where they meet and then they all execute the second
 * part of the code before theBarrier->phaseTwo() where they meet again and pass
 * through
 *
 * @param theBarrier Used to implement a reusable barrier lock
 * @param numLoops For loop executes for numLoops times
 */
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    std::cout << "A"<< i;
    theBarrier->phaseOne();
    //Do second half of task
    std::cout<< "B" << i;
    theBarrier->phaseTwo();
  }
}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  return 0;
}
