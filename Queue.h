//----- Queue.h -----
#include <iostream>
#include <string>
using namespace std;

/* Queue.h contains the declaration of class Queue.
   Basic operations:
     Constructor: Constructs an empty queue
     empty:       Checks if a queue is empty
     enqueue:     Modifies a queue by adding a value at the back
     front:       Accesses the front queue value; leaves queue unchanged
     dequeue:     Modifies a queue by removing the value at the front
     display:     Displays the queue elements from front to back
   Class Invariant:
      1. The queue elements (if any) are stored in consecutive positions
         in myArray, beginning at position myFront.
      2. 0 <= myFront, myBack < QUEUE_CAPACITY
      3. Queue's size < QUEUE_CAPACITY
-----------------------------------------------------------------------*/
#ifndef LAB3_EGGENSPERGER_MARIYA_QUEUE_H
#define LAB3_EGGENSPERGER_MARIYA_QUEUE_H

/**
 * Title: Lab 3 Submission : Queue Text String
 * Course: CST 370 Design & Analysis of Algorithms
 * School: CSU, Monterey Bay
 * Professor: Dr. Feiling Jia
 * Source: CLion 2016.3.2 on 1/22/2017
 *
 * Header file defines the data for a queue program
 * that reads a document containing endnotes, Sample.txt,
 * collects them in a queue, and prints them on the screen.

 *
 * @author Mariya Eggensperger
*/

const int QUEUE_CAPACITY = 128;
typedef string QueueElement;

class Queue
{
public:
    /*----- Function Members -----*/

    Queue(); // Constructor

    bool is_empty() const;
    void enqueue(const QueueElement & value);
    void dequeue();
    QueueElement front() const;
    void display(ostream & out) const;

private:

    /*----- Data Members -----*/

    int myFront, myBack; // Value at the front of queue and back of queue
    QueueElement myArray[QUEUE_CAPACITY]; //Queue of 128 elements

}; // End of Queue() class declaration

#endif //LAB3_EGGENSPERGER_MARIYA_QUEUE_H
