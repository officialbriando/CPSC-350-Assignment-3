Author: 
Brian Do

Project Details:

1. Implement your own stack class based on arrays. To avoid naming conflicts, call it
GenStack. It should implement all the operations one would expect to see for this
data structure. Your stack class must be generic (meaning it can hold any type of
data – think templates), and it must automatically allocate more room for itself when
it fills up. If the pop operation is called when the stack is empty, you should throw a
an exception. Write your code in such a way that it can be reused in future projects.

2. Write a program that takes the location of a source code file to be analyzed as a
command line argument. (eg. ./assign3 foo.cpp).

3. If the delimiters in the file are ok, report to the user that the delimiter syntax is
correct, and ask if they want to analyze another file.
4. If there is a problem, you must tell the user the location of the problem, as well as what
the problem is. (eg. “Line 20: expected ) and found ]” or “Reached end of file:
missing }”) The program should then exit so as to allow the user to fix the error. (In
other word


References:
Data Structures & Algorithms in C++ - Goodrich
-Used to look at setting up the template class for STL Stacks.
