/*
  This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
/*! \mainpage Lab 6 - Producer-Consumer
 * \author Peter Lucan, 4th Year Software Development student at IT Carlow,C00228946, c00228956@itcarlow.ie
 * \date 20/12/2020
 * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
 * \section desc_sec Decription
 *
 * Description: Implementation of a Stack.
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

#include <array>

class SafeBuffer{
    int top;
    int maxSize;
    char stack[10];

    public: SafeBuffer(){
        top = -1;
        maxSize = 10;
    }

    ~SafeBuffer();
    void push(char letter);
    void pop(char letter);
    void peek();
    bool isEmpty();
    bool isFull();
};