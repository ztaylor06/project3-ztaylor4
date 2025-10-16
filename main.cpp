#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    // Example of writing out to a file
    ofstream outFileE;
    outFileE.open("../data/example_output.csv");
    for (int i = 999; i >= 0; --i) {
        outFileE << i << endl;
    }
    outFileE.close();

    // Example of how to declare and use a tree object

    BinarySearchTree<int> bst1;
    for (int i = 0; i < 100; i++) {
        bst1.add(i);
    }

    ofstream OutFile("../data/list.csv");

    for (int i = 0; i < 100; i++) {
        int depth = bst1.find(i);
        OutFile << "depth:" << depth << "," << "number:" << i << endl;
    }

    cout << bst1.find(0) << endl;
    cout << bst1.find(101) << endl;
    cout << bst1.find(102) << endl;

    OutFile.close();

    SplayTree<int> test;
    for (int i = 0; i < 100; ++i) {
        test.add(i);
    }

    ofstream OutFile6("../data/list2.csv");

    for (int i = 0; i < 100; ++i) {
        int depth = test.find(i);
        OutFile6 << "depth:" << depth << "," << "number:" << i << endl;
    }

    OutFile6.close();

    AVLTree<int> avl1;
    for (int i = 0; i < 100; ++i) {
        avl1.add(i);
    }

    ofstream OutFile7("../data/list3.csv");

    for (int i = 0; i < 100; ++i) {
        int depth = avl1.find(i);
        OutFile7 << "depth:" << depth << "," << "number:" << i << endl;
    }

    OutFile7.close();

    int arr[100];
    for (int i = 0; i < 100; ++i) arr[i] = i + 1;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(arr), std::end(arr), g);

    BinarySearchTree<int> bst2;
    AVLTree<int> avl2;
    SplayTree<int> test2;

    for (int i = 0; i < 100; ++i) {
        bst2.add(arr[i]);
        avl2.add(arr[i]);
        test2.add(arr[i]);
    }

    ofstream OutFile8("../data/avlRand.csv");
    ofstream OutFile9("../data/bstRand.csv");
    ofstream OutFile10("../data/splayRand.csv");

    for (int i = 0; i < 100; ++i) {
        int j = arr[i];
        int depth = avl2.find(j);
        OutFile8 << "depth:" << depth << "," << "number:" << j << endl;
        OutFile9 << "depth:" << depth << "," << "number:" << j << endl;
        OutFile10 << "depth:" << depth << "," << "number:" << j << endl;
    }

    BinarySearchTree<Student> bst3;
    AVLTree<Student> avl3;
    SplayTree<Student> test3;

    vector<Student> students;
    getDataFromFile(students);

    for (int i = 0; i < 1000; ++i) {
        bst3.add(students[i]);
        avl3.add(students[i]);
        test3.add(students[i]);
    }

    ofstream OutFile2("../data/bstlist.csv");
    ofstream OutFile3("../data/avllist.csv");
    ofstream OutFile4("../data/splaylist.csv");

    for (int i = 0; i < 1000; ++i) {
        OutFile2 << students[i].getID() << "," << bst3.find(students[i]) << endl;
        OutFile3 << students[i].getID() << "," << avl3.find(students[i]) << endl;
        OutFile4 << students[i].getID() << "," << test3.find(students[i]) << endl;
    }

    OutFile2.close();
    OutFile3.close();
    OutFile4.close();

    SplayTree<Student> splay;
    ofstream OutFile5("../data/splaylist2.csv");

    for (int i = 0; i < 1000; ++i) {
        splay.add(students[i]);
    }

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 5; ++j) {
            OutFile5 << students[i].getID() << "," << splay.find(students[i]) << endl;
        }
    }

    OutFile5.close();

    return 0;
}



