//----- Queue.cpp -----
#include <iostream>
using namespace std;

#include "Queue.h"
/**
 * Title: Lab 3 Submission : Queue Text String
 * Course: CST 370 Design & Analysis of Algorithms
 * School: CSU, Monterey Bay
 * Professor: Dr. Feiling Jia
 * Source: CLion 2016.3.2 on 1/22/2017
 *
 * This file implements the queue member functions for
 * a program that reads a document containing endnotes,
 * Sample.txt, collects them in a queue, and prints
 * them on the screen.
 *
 * @author Mariya Eggensperger
*/

/**
 * Default constructor. Construct an empty Queue object.
 *
 * @param args myFront and myBack are initialized to -1
 * and myArray is an array with QUEUE_CAPACITY elements
 * of type QueueElement.
 * @return
*/
Queue::Queue()
        : myFront(0), myBack(0) // No values in the front || back of queue
{}
/**
 * Boolean check if a queue is empty.
 *
 * @param args True is returned if the queue
 * is empty and false is returned otherwise.
 * @return myFront == myBack
*/
bool Queue::is_empty() const
{
   return (myFront == myBack);
}
/**
 * Add a value to a queue.
 *
 * @param args Value is to be added to the back
 * of this queue, provided there is space; otherwise,
 * a queue-full message is displayed and execution
 * terminated.
 * @return bool return
*/
void Queue::enqueue(const QueueElement & value)
{
   int newBack = (myBack+1) % QUEUE_CAPACITY;
   if(newBack != myFront) // If queue is not full
   {
      myArray[myBack] = value;
      myBack = newBack;
   }
   else
   {
      cerr << "\nQueue full. Cannot add value." <<endl;
      exit(1); // Terminate program
   }
}
/**
 * Remove a value from the front of a queue, if any.
 *
 * @param args Queue is nonempty. Value at the front of queue is
 * removed, unless queue is empty; in this case, an error message
 * is displayed and program is terminated.
 * @return void return
*/
void Queue::dequeue()
{
   if(!is_empty())// If is not empty
   {
      myFront = (myFront+1) % QUEUE_CAPACITY;
   }
   else
   {
      cerr << "\nQueue is empty. Cannot remove value." <<endl;
      exit(1); // Terminate program
   }
}
/**
 * Retrieve value at front of queue (if any).
 *
 * @param args Queue is nonempty. Value at front of queue
 * is returned, unless queue is empty; in that case, an
 * error message is displayed and a "garbage value" is returned.
 * @return QueueElement garbage_value
*/
QueueElement Queue::front() const
{
   if(!is_empty()) //If not is empty
   {
      return (myArray[myFront]);
   }
   else
   {
      cerr << "\nQueue is empty. Returning a garbage value." <<endl;
      QueueElement garbage_value = "1111";
      return garbage_value;
   }
}
/**
 * Output the values stored in the queue.
 *
 * @param args List object is inserted into out, the ostream out is open.
 * @return void return
*/
void Queue::display(ostream &out) const {
   for (int i = myFront; i != myBack; i = (i + 1) % QUEUE_CAPACITY)
      out << myArray[i] << "  ";
   cout << endl;
}
