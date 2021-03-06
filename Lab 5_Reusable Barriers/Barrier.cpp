// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: Two functions which implement a barrier.
// Author: Joeseph Kehoe
// Maintainer: Peter Lucan
// Created: Tue Jan  8 12:14:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Fri Nov 20 21:06:21 2019 (+0000)
//           By: Peter Lucan
//     Update #: 3
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

Barrier::~Barrier()
{
    /**Nothing to Do Here */
}
void Barrier::phaseOne()
{
   theLock.Wait();
   ++threadCount;
   if (threadCount == threadTotal)
   {
       std::cout << std::endl;
       turnstileTwo.Wait();
       turnstileOne.Signal();
   }
   theLock.Signal();
   turnstileOne.Wait();
   turnstileOne.Signal();
   
}//phaseOne

void Barrier::phaseTwo()
{
    theLock.Wait();
    --threadCount;
    if(threadCount == 0)
    {   
        std::cout << std::endl;
        std::cout << std::endl;
        turnstileOne.Wait();
        turnstileTwo.Signal();
    }
    theLock.Signal();
    turnstileTwo.Wait();
    turnstileTwo.Signal();
}
void Barrier::wait()
{
  phaseOne();
  phaseTwo();  
}
// 
// Barrier.cpp ends here
