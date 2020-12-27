/*
  This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
/*! \mainpage Lab 6 - Producer-COnsumer
 * \author Peter Lucan, 4th Year Software Development student at IT Carlow,C00228946, c00228956@itcarlow.ie
 * \date 20/12/2020
 * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
 * \section desc_sec Decription
 *
 *  Description: Implementation of a Stack.
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

#include "SafeBuffer.h"
#include <iostream>

/*! \fn SafeBuffer::~SafeBuffer() = default;
    \brief This is a destructer for this class
*/
SafeBuffer::~SafeBuffer() = default;

/*! \fn isEmpty()
    \brief This function returns true if empty and false if not empty
*/
bool SafeBuffer::isEmpty(){
  if (top == -1){
    return true;
  }
  else {
    return false;
  }
}

/*! \fn isFull()
    \brief This function returns true if full and false if not full
*/
bool SafeBuffer::isFull(){
  if (top == maxSize){
    return true;
  }
  else {
    return false;
  }
}

/*! \fn push(char letter)
    \param letter is the character that is being added to the stack
    \brief This function adds a letter to the stack if it's not full
*/
void SafeBuffer::push(char letter){
  if(isFull()){
    std::cout << "The stack is Full" << std::endl;
  }
  else{
    top = top + 1;
    stack[top] = letter;
    std::cout << "Pushed: " << letter << std::endl;
  }
}

/*! \fn pop(char letter)
    \param letter is the character that is being taken from the stack
    \brief This function takes a letter from the stack if it's not empty
*/
void SafeBuffer::pop(char letter){
  if (isEmpty()){
    std::cout << "The stack is empty" << std::endl;
  }
  else {
    letter = stack[top];
    top = top - 1;
    std::cout << "Popped " << letter << std::endl;
  }
}

/*! \fn peek()
    \brief This function can be used to take a look at the top letter in the stack
*/
void SafeBuffer::peek(){
  std::cout << "Top: " << top << std::endl;
}