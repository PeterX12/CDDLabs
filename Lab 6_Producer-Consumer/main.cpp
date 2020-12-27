/*
  This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
/*! \mainpage Lab 6 - Producer-Consumer
 * \author Peter Lucan, 4th Year Software Development student at IT Carlow,C00228946, c00228956@itcarlow.ie
 * \date 20/12/2020
 * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
 * \section desc_sec Decription
 *
 * Description: This is the sixth lab which demonstrates the producer consumer problem. Threads produce letters that are pushed onto a stack and also consume them by popping them from the stack. This is done cocnurently. The letters are pushed and popped in order.
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
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include "Semaphore.h"
#include "SafeBuffer.h"

/*! \Varaibles for the amount of theradd that will execute and the characters that will get popped or pushed.
*/
static const int num_threads = 10;
char character;


/*! \fn producer
    \param stack is the stack argument to which the characters are produced and added to.
    \param mutext is the mutex lock that makes sure that only on thread can access the stack at a time
    \param consumer signals the consumer thread
    \param numLoops specifies how many times the for loop should run
    \brief Creates characters and adds them to the stack.
*/

void producer(std::shared_ptr<SafeBuffer> stack, std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> consumer, int numLoops){

  for(int i=0;i<numLoops;++i){
    mutex->Wait();
    character = 'a'+rand()%26;
    std::cout << "Push: ";
    stack->push(character);
    mutex->Signal();
    consumer->Signal();
  }
  

}

/*! \fn consumer
    \param stack is the stack argument from which the characters are taken from.
    \param mutext is the mutex lock that makes sure that only on thread can access the stack at a time
    \param consumer signals the consumer thread
    \param numLoops specifies how many times the for loop should run
    \brief Takes characters from the stack
*/

void consumer(std::shared_ptr<SafeBuffer> stack, std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> consumer, int numLoops){

  for(int i=0;i<numLoops;++i){
    consumer->Wait();
    mutex->Wait();
    std::cout << "Poped: ";
    stack->pop(character);
    mutex->Signal();
  }
  

}

int main(void){

  std::vector<std::thread> prod(num_threads);
  std::vector<std::thread> con(num_threads);

  std::shared_ptr<SafeBuffer> stack( new SafeBuffer());
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> consumers( new Semaphore(0));

  /**< Launch the threads  */
  for(std::thread& p: prod){
    p=std::thread(producer,stack,mutex,consumers,2);
  }
  /**< Join the threads with the main thread */
  for (auto& p :prod){
      p.join();
  }
   std::cout << " " << std::endl;
  /**< Launch the threads  */
  for(std::thread& c: con){
    c=std::thread(consumer,stack,mutex,consumers,2);
  }
  /**< Join the threads with the main thread */
  for (auto& c :con){
      c.join();
  }
  return 0;
}
