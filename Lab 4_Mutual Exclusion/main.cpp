/*
  This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
/*! \mainpage Lab 4 - Mutual Exclusion
 * \author Peter Lucan, 4th Year Software Development student at IT Carlow,C00228946, c00228956@itcarlow.ie
 * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
 * \section desc_sec Decription
 *
 * Description: This is the Fourth lab. A Mutex is used to ensure that only one thread acesses the shared variable at a time. This is achieved using two Semaphores
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
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
/**
 * The udpateTask function
 *
 * This function uses a hundread threads to increment a shared variable 1000 times each.
 *Whichever thread gets to the wait first will be able
 *to proceed immediately. Of course, the act of waiting on the semaphore has the
 *effect of decrementing it, so the second thread to arrive will have to wait until
 *the first signals.
 * @param firstSem Used to implement a mutex lock
 * @param numUpdares For loop executes for numupdates times
 */
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){


  for(int i=0;i<numUpdates;i++){
    firstSem->Wait();
    sharedVariable++;
    firstSem->Signal();
  }

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
