# Project 3 Report

Answer the following questions directly in this file:
* You will have a different grader again, so make sure your report includes information about your dataset.
I used a dataset of student's exam grades with the amount of time they studied and slept
The number I used for comparison operators was the amount of hours studied.
* How do the depths of the random-ordered integers compare to the depths of the ordered integers for each tree? Why?
For the AVL Trees: The random ordered integers fluctuate from depths 1-7 while the ordered integers tend to stay around depths 5-6
For the BST trees: The random ordered integers depths are more inconsistent because the root node is chosen randomly.
The ordered pair of the binary search tree has the same depth as the number, because as the nodes are added to the tree in an increasing order they are always added to the right side since they are a greater number.
For the Splay Trees: The random ordered integers never go below a depth of 7 while the ordered integers start at depth 99 with 0
* How do the depths of each custom-data-type tree compare to each other?
The splay tree has the deepest depth of any of the trees.
The AVL and BST trees have around the same depths on average with the avl tree having slightly lower depth on average.
* Why do the depths of the second custom-data-type Splay Tree make sense?
The depth returns 0 after the first iteration because the splay rotation has already been made and now the numebr has become the root node.
* Graph the Binary Search Tree, AVL Tree, and Splay Tree depths for the custom data type trees. Do not use C++ to graph, you can use whatever spreadsheet application or graphical programming language you prefer. You can use whatever graph is most readable to you (e.g. scatter plot, histogram, etc.).
  * Your graphs should have clear labels for both x and y axes.
  * Save your graph files in the graphs folder.
  * You do not need to graph the depths of the integer type trees or the Splay Tree that finds each object 5 times in a row, but you can if you feel it helps you analyze the data.
  * An example graph spreadsheet and an example graph image have been included in the starter code.
  * Here is how you include an image in your Report.md file: ![example graph](graphs/example-graph.png)
    * Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.
      ![BST](graphs/BST.png)
      ![AVL](graphs/AVLTree.png)
      ![SplayTree](graphs/SplayTree.png)
    **Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**