#Author: Peter Lucan
#Student Number: C00228946
#Date: 20/11/2020
#Description: Makfile which compiles files and produces an executable and also deletes all object files.
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread
DEBUGFLAGS= -Wall

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

#This compiles the neccesary files and creates an executable file. The last line removes all object files.
ALL: main.o
	$(CC) main.cpp Semaphore.cpp SafeBuffer.cpp $(CFLAGS) -o prodCon $(DEBUGFLAGS)
	rm *.o

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o