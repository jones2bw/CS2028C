Data Structures (2028C) -- Spring 2020 – Lab 9
Topics covered: Working with Binary Search Trees
Lab due: Wednesday, April 8 at 11:55PM 

Objective:
The objective of this homework is to create an implementation of a Binary Search Tree.

Scenario:
In your first homework assignment, you created a program that counted the number of words and the frequency of each letter.  This assignment will leverage your code from that assignment to read a file but with a modification.  Instead of counting the frequency of each letter, you are going to count the frequency of each word.  You will use a Binary Search Tree to store each word along with its count.  This needs to be written using C++.

Requirements:
1.	Create a templated Binary Search Tree class with the following methods.  You may need or find it easier to create private methods and variable to simplify or eliminate duplicate code in the methods below such as RotateRight, RotateLeft or NodeHeight.
a.	Constructor
b.	Destructor
c.	Insert – accepts a value, creates a node and inserts the node into the tree in the appropriate location.  This should rebalance the tree as necessary, so the tree remains balanced at all times.  If the value already exists in the tree, this should throw an error.
d.	Find – accepts a value, locates the value in the tree and returns a pointer to the node.  If the value isn’t in the tree, it will return a null pointer.
e.	Size – returns the number of elements in the tree as an integer.
f.	GetAllAscending – returns an array with each node stored in order from smallest to largest (based on the sorting value, not the other data in the node).
g.	GetAllDescending – returns an array with each node stored in order from largest to smallest (based on the sorting value, not the other data in the node).
h.	EmptyTree – removes all nodes in the tree in a way to avoid memory leaks.
i.	Remove – accepts a value, finds the value and removes it from the tree.  A pointer to the removed node is returned.  This should rebalance the tree as necessary, so the tree remains balanced at all times.
2.	Modify your program from Homework 1 to read the input file and count the frequency of each word using the Binary Search Tree in step 1.  This is likely not the best data structure for performing this function but this is the data structure we are currently learning about so we will use it.  Your program should create a class made up of a string and an int that will be used as the type of the templated Binary Search Tree.  The string will be the word you are reading in and should be the key you are comparing at each level.  The int is the count for that word.  You may need to overload <, > and/or == operators for this class to be used in your Tree.  You can use the Find function to find the word in the tree then update the count via the returned node pointer.  If Find returns a null pointer, you will need to call Insert.  Once the file is read and loaded to the tree, let the user search for a word. If it is found, return the count.  If it is not, indicate such.  Also, allow the user to see a list of all words with count in alphabetic order both ascending and descending (Task 1-part f and g)

Submission:
Submit all source code files and any required data files in a zip file.  Include a write up as a PDF including:
•	The name of all group members (minimum 2 members, maximum 4 members).
•	Instructions for compiling and running the program including any files or folders that must exist.
•	What each group member contributed.  If the contributions are not equitable, what portion of the grade each group member should receive.
Submission should be made via Canvas.
TA: muppalsa@mail.uc.edu
  

Grading:
1.	25% - BinarySearchTree class functions Insert, Find and Remove work correctly (excepting for keeping the tree balanced) including avoiding memory leaks.
2.	25% - BinarySearchTree stays balanced at all times with a difference of the longest path to a leaf and the shortest path to a leaf no greater than 2.
3.	15% - The other required functions of the BinarySearchTree work correctly including avoiding memory leaks.
4.	10% - Your main code correctly reads the input files and creates a Binary Search Tree.
5.	15% - Your main code correctly Allows the user to search for words and returns the correct result and outputs the full list in ascending and descending order.
6.	10% - Code is well formatted, well commented and follows a reasonable style.
If program fails to compile, the grade will be limited to a max grade of 50%.

