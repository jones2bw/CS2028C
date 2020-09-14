Data Structures (2028C) -- Spring 2020 – Lab 10
Topics covered: Hashing
Lab due: Monday, Apr 13 at 11:55PM

Objective:
The objective of this Lab is to explore creating and using Hash Tables.


Task 1:  Create a Hash Table that uses linear probing.
1.	Create a new project.  You can name this whatever you like.
2.	Design and implement Hash Table class using linear probing as described in class.  This class should be a template.  The template is expected to have overloaded the == operator and the string object conversion  (you don’t need to write these overloads as part of your Hash table, it will be in the data type you are storing in your hash table).
a.	The class should have the following methods fully implemented.
i.	Constructor – This should have an overload indicating the maximum number of items the Hash table can store.  The default value is 100.
ii.	Hash – This should be a private function that accepts a string and returns an int.  For this, we are going to add the sum of all the ASCII values for the passed in string and modulus by the maximum size of the table.
iii.	AddItem – adds an item from the list.
iv.	RemoveItem – searches the list for the given item.  If found, it removes it from the list and returns it.  If not found, it returns a null pointer.
v.	GetItem – searches the list for a given item.  If found, it returns a pointer to the item but doesn’t remove it from the list.
vi.	GetLength – returns an int indicating the number of items in the table.
vii.	Destructor
b.	All items passed to or from the class should be done so via a pointer rather than by value.
c.	Make sure you don’t have any memory leaks.
Complete this before moving on to task 2.

Task 2:  Reuse the class from Lab 8, Task 2 (Class to store data).  You will need to add the overload of the string object conversion.  This object conversion should return the SKU Number.
Complete this before moving on to task 3.

Task 3:  Modify your test program from Lab 8, Task 3 (test program) to test your Hash Table class.  Include a screen shot of some of this testing in your lab report.
Complete this before moving on to task 4.
 
Task 4:  Create a derived class from your Hash table that implements a chained hash table.  Use your linked list class from Lab 8, Task 1.  Modify your test program from Task 3 to test this new class.  Include a screen shot of some of this testing in your lab report.
Complete this before moving on to task 5.

Task 5: Measure the performance of the linear probing and chained linking implementations of a hash table (similar to Lab 7 task 4).  To do this, modify both classes to keep track of the number of times an item is compared in the chain for chained linking  and the number of times an additional index is checked for linear probing (you only need to do this for the GetItem but you can do it for both if that is easier). Create a test program that adds 50 randomly generated students (follow appropriate SKU Number rules) to both hash tables then calls GetItem on the same student.  Record the total number of times the Hash Table needed to complete the 50 operations.  Repeat this measurement with an array size of 150, 200 and 250.  Include a table of the results from the 4 trials for the 2 different classes in your lab report. 

Lab Submission:
1.	Write a lab report including the following information:
a.	A description of the objectives/concepts explored in this assignment including why you think they are important to this course and a career in CS and/or Engineering.
b.	The sections from each task indicated to be included in the lab report. 
2.	Include all source code from all tasks, input and output files (if any), and any special instructions to compile and run those programs.
3.	Include a discussion of what modifications you needed to make for Task 2 and Task 3.
4.	Include a discussion of why you think the results for Task 5 were what they were.  This should suggest ideas for further investigation.
5.	Mention the contribution of each member explicitly in the lab report.
6.	Mention special instructions, if any, to run the code.
7.	Package all files in a single zip folder and submit the file to canvas.
8.	TA: muppalsa@mail.uc.edu 

Lab Grading:
1.	25% - Task 1 has been correctly implemented and meets all requirements.
2.	10% - Task 2 has been correctly implemented and meets all requirements. 
10% - Task 3 has been correctly implemented and meets all requirements. 
3.	15% - Task 4 has been correctly implemented and meets all requirements.
4.	25% - Task 5 has been correctly implemented and meets all requirements.  The discussion makes sense and includes suggestions for further investigation.
5.	15% - Lab report contains all required information and is well written.
If program fails to compile, 0% will be given for that Task.
