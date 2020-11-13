 /*
   This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
  */
 /*! \mainpage Lab Two: Signalling with Semaphores
  * \author Peter Lucan
  * \date 09 October 2020
  * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
  * \section desc_sec Decription
  *
  * This is the Second lab. This lab is about using Semaphores to make on thread fully execute before another thread is allowed to execute.
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
#include <unistd.h>
/**
 * The taskOne function
 *
 * This function waits for a specified amount of time before printing some text. Thanks to the last line the function runs to completion first.
 *
 * @param theSemaphore Used to ensure this task runs to completion first!
 * @param delay Task sleeps fpr delay seconds before starting
*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
/**
 * The taskTwo function
 *
 * This function waits for the first function to signal before it runs.
 *
 * @param theSemaphore Used to ensure this task runs to completion first!
 */
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
