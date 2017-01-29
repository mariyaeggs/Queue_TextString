//----- Queue_Tester.cpp -----
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Queue.h"
/**
 * Title: Lab 3 Submission : Queue Text String
 * Course: CST 370 Design & Analysis of Algorithms
 * School: CSU, Monterey Bay
 * Professor: Dr. Feiling Jia
 * Source: CLion 2016.3.2 on 1/22/2017
 *
 * This is a driver program to test the queue class for a
 * a program that reads a document containing endnotes,
 * Sample.txt, collects them in a queue, and prints
 * them on the screen.
 *
 * @author Mariya Eggensperger
*/
int main () {

   ifstream myfile("sample.txt");

   Queue q;
   string line;
   string temp_str = "";
   bool is_stored = false;


   if(myfile.is_open()) {
      while (!myfile.eof()) {
         getline(myfile, line);
         temp_str += line;
      }
   } else {
      cout << "File cannot be opened.";
      return 1;
   }
   myfile.close();
   string str_queue = "";
   for (char c : temp_str) {
      if (c == '}') {
         is_stored = false;
         if(!str_queue.empty()) { // If the string is not empty
            q.enqueue(str_queue);
         }
         str_queue = ""; // Clear str_queue
      }
      if (is_stored) {
         str_queue += c;
      }
      if (c == '{') {
         is_stored = true;
      }
   }
   while(!q.is_empty()) {
      cout << q.front() << endl;
      q.dequeue();
   }
}



