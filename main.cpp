#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Example of writing out to a file
    ofstream outFile;
    outFile.open("../data/example-output.csv");
    for (int i = 999; i >= 0; --i) {
        outFile << i << endl;
    }
    outFile.close();

    // Example of how to declare and use a tree object
    BinarySearchTree<int> bst1;
    if (!bst1.add(8)) {
        cout << "Could not add 8 to the tree." << endl;
    }
    if (bst1.find(8)) {
        cout << "Found 8 in the tree." << endl;
    }
    if (bst1.getSize() != 1) {
        cout << "There are " << bst1.getSize() << " nodes in the tree." << endl;
    } else {
        cout << "There is one node in the tree." << endl;
    }
    bst1.timber();

    SplayTree<int> test;
    for (int i = 0; i < 100; ++i) {
        if (!test.add(i)) {
            cout << "Could not add " << i << endl;
        }
    }
    cout << "Size: " << test.getSize() << endl;
    for (int i = 0; i < 100; ++i) {
        if (!test.find(i)) {
            cout << "Could not find " << i << endl;
        }
    }
    return 0;
}