# CS 2240 Project 3

Explore Binary Search trees, AVL trees, and Splay trees!

For this project, you will store your 1000+ objects in a Binary Search Tree, an AVL Tree, and a Splay Tree. You will search for objects in the tree and record how many objects you had to visit to complete the search. You will analyze your results from the different data structures.

## Setup
You will want to start at the end of Project 1. You should have a vector of 1000+ objects in your main function.
* You will need to overload the <, >, <=, >=, and == operators of your class from Project 1. Use the unique field to compare objects of your class to ensure that all objects get stored in the trees.

## Requirements

### Tree Classes
Modify the find methods of each tree class (Binary Search Tree, AVL Tree, and Splay Tree) so that a search of the tree also stores the depth of the last node visited. To do this without losing information, pass an integer by reference into both find methods and modify the integer inside the methods.
* The root node is at depth 0.
* Even if the search fails, you should still record the depth of the last node visited.

### Main Function
Create a Binary Search Tree, an AVL Tree, and a Splay Tree all of type integer. Using a loop, insert the integers from 1 to 100 in order. In a second loop, find each integer in order and record the depths to a file in the data folder.
* Check for understanding: print the return values and depths you get from the BST find method if you search for 0, 101, and 102 (you should get 1, 100, and 100, respectively).

Create a Binary Search Tree, an AVL Tree, and a Splay Tree all of type integer. Using a loop, insert the integers from 1 to 100 in a random order. In a second loop, find each integer in order and record the depths to a file in the data folder.
* You can get a random sequence either from random.org or by shuffling a vector of numbers (C++ has a shuffle function).

Create a Binary Search Tree, an AVL Tree, and a Splay Tree all of your custom data type. Using a loop, insert all 1000+ objects into the trees in the order they appear in your vector (hint: use `getSize` to make sure all of your data was stored in each tree). In a second loop, find each custom object in the same order and record the depths to a file in the data folder.

Create another Splay Tree of your custom data type. Using a loop, insert all 1000+ objects in the order they appear in your vector. In a second loop, find each object five times in a row before searching for the next object and record the depths to a file in the data folder.
* You should have 5000+ depths stored in the file for this tree.
* You should have a total of 10 tree objects in main.

### Report
You must write a report about your project. Answer the prompts in the Report.md file.

## Submit
You must include your source files (including the three modified tree header files, your class header file, and the main program file), your data files (including your .csv data file and all of the output depth files), your image files (including all graphs you analyze in your report), CMakeLists.txt, and your updated Report.md to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Extra Credit
To earn up to 10 extra credit points (at the grader’s discretion), you can get more thorough results. This can include:
* Setting timers to record how long it takes you to search for the objects in each data structure and analyzing the results
* Performing more experiments with the order of insertions/searches and analyzing the results
* Performing the same experiments on 100, 200, 300, …N objects and graphing the results

Note that if you add this logic to your code but do not analyze it in your report, it will not count towards extra credit. If you choose to complete extra credit, specifically indicate it with analysis in your Report.md file.

## Grading
The project is out of 80 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 15 pts | The three BSTs in the main function are complete and correct |
| 15 pts | The three AVL Trees in the main function are complete and correct |
| 20 pts | The four Splay Trees in the main function are complete and correct |
| 20 pts | Report: analysis of results, professional, grammatically correct, cites sources. |
