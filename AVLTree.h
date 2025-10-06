#ifndef PROJECT3STARTER_AVLTREE_H
#define PROJECT3STARTER_AVLTREE_H

#include <memory>

template <typename Comparable>
class AVLTree {
private:
    struct AVLNode {
        Comparable value;
        AVLNode* leftChild;
        AVLNode* rightChild;
        int height;

        // Constructors
        AVLNode() : value(Comparable()), leftChild(nullptr), rightChild(nullptr), height(0) {}
        explicit AVLNode(Comparable c) : value(c), leftChild(nullptr), rightChild(nullptr), height(0) {}
        AVLNode(Comparable c, AVLNode* l, AVLNode* r, int h = 0) : value(c), leftChild(l), rightChild(r), height(h) {}
    };
    AVLNode* root;
    unsigned long size;

    // Helper recursive function to destroy the tree.
    void destroy(AVLNode* &n) {
        if (n != nullptr) {
            destroy(n->leftChild);
            destroy(n->rightChild);
            delete n;
            n = nullptr;
        }
    }

    // Helper recursive function to copy the tree.
    AVLNode* copyNode(AVLNode* n) {
        if (n == nullptr) {
            return nullptr;
        }
        ++size;
        return new AVLNode(n->value, copyNode(n->leftChild), copyNode(n->rightChild));
    }

    // Helper recursive function to find a value in the tree.
    bool find(const Comparable &c, AVLNode* n) const {
        if (n == nullptr) {
            // Reached a dead end. Value not in tree.
            return false;
        }
        if (c < n->value) {
            // Value is less than current node. Go to node's left child.
            return find(c, n->leftChild);
        }
        if (n->value < c) {
            // Value is greater than current node. Go to node's right child.
            return find(c, n->rightChild);
        }
        // If code reaches here, c == n->value. Node found!
        return true;
    }

    int getNodeHeight(AVLNode* &n) const {
        return (n == nullptr) ? -1 : n->height;
    }

    void calculateNodeHeight(AVLNode* &n) {
        int leftHeight = getNodeHeight(n->leftChild);
        int rightHeight = getNodeHeight(n->rightChild);
        n->height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }

    // Helper method to perform a single right rotation.
    void singleRotationRight(AVLNode* &n) {
        // n's left child has to move up,
        // n has to move down to the right.
        AVLNode* temp = n;
        n = n->leftChild;
        temp->leftChild = n->rightChild;
        n->rightChild = temp;
        calculateNodeHeight(n->rightChild);
        calculateNodeHeight(n);
    }

    // Helper method to perform a single left rotation.
    void singleRotationLeft(AVLNode* &n) {
        // n's right child has to move up,
        // n has to move down to the left.
        AVLNode* temp = n;
        n = n->rightChild;
        temp->rightChild = n->leftChild;
        n->leftChild = temp;
        calculateNodeHeight(n->leftChild);
        calculateNodeHeight(n);
    }

    // This method ensures the AVL balancing property.
    void balance(AVLNode* &n) {
        if (n == nullptr) {
            // Nothing to do.
            return;
        }
        if (getNodeHeight(n->leftChild) - getNodeHeight(n->rightChild) > 1) {
            // Left side is heavy.
            if (getNodeHeight(n->leftChild->leftChild) >= getNodeHeight(n->leftChild->rightChild)) {
                // Left-left case. Need single rotation to the right.
                singleRotationRight(n);
            }
            else {
                // Left-right case. Need double rotation (left-right).
                singleRotationLeft(n->leftChild);
                singleRotationRight(n);
            }
        }
        else if (getNodeHeight(n->rightChild) - getNodeHeight(n->leftChild) > 1) {
            // Right side is heavy.
            if (getNodeHeight(n->rightChild->rightChild) >= getNodeHeight(n->rightChild->leftChild)) {
                // Right-right case. Need single rotation to the left.
                singleRotationLeft(n);
            }
            else {
                // Right-left case. Need double rotation (right-left).
                singleRotationRight(n->rightChild);
                singleRotationLeft(n);
            }
        }
        calculateNodeHeight(n);
    }

    // Helper recursive function to add a value to the tree.
    bool add(const Comparable &c, AVLNode* &n) {
        if (n == nullptr) {
            // We found the place where we can add the node.
            n = new AVLNode(c, nullptr, nullptr);
            ++size;
            // Now that we have added the node, balance the tree if necessary.
            balance(n);
        }
        else if (c < n->value) {
            // Value is less than current node. Go to left child.
            bool returnVal = add(c, n->leftChild);
            balance(n);
            return returnVal;
        }
        else if (n->value < c) {
            // Value is greater than current node. Go to right child.
            bool returnVal = add(c, n->rightChild);
            balance(n);
            return returnVal;
        } else {
            // Value is a duplicate. Cannot add it to the tree.
            return false;
        }
        return true;
    }

    // Helper recursive method to find the maximum value from a given node.
    Comparable& findMax(AVLNode* n) {
        if (n->rightChild == nullptr) {
            return n->value;
        }
        return findMax(n->rightChild);
    }

    // Helper recursive function to delete a value from the tree.
    void remove(const Comparable &c, AVLNode* &n) {
        if (n == nullptr) {
            // We did not find the value. Cannot remove it. Nothing to do.
            return;
        }
        else if (c < n->value) {
            // Value is less than current node. Go to left child.
            remove(c, n->leftChild);
        }
        else if (n->value < c) {
            // Value is greater than current node. Go to right child.
            remove(c, n->rightChild);
        }
            // If code reaches here, we found the node. Now to remove it.
        else if (n->leftChild != nullptr && n->rightChild != nullptr) {
            // The node we want to remove has two children
            // Find the largest value from the left subtree
            n->value = findMax(n->leftChild);
            remove(n->value, n->leftChild);
        }
        else {
            // The node we want to remove has 0 or 1 child.
            // If it has a child, move it up. If not, set to nullptr.
            AVLNode *oldNode = n;
            n = (n->leftChild != nullptr) ? n->leftChild : n->rightChild;
            delete oldNode;
            oldNode = nullptr;
            --size;
        }
        // Now that we have removed the node, balance the tree if necessary.
        // Note that because of the recursion, this will be called for every
        // node on the path from the root to where the new node is placed.
        balance(n);
    }

public:
    // Default Constructor
    AVLTree() {
        root = nullptr;
        size = 0;
    }

    // Copy Constructor
    AVLTree(const AVLTree &b) {
        size = 0;
        // calls private helper function
        root = copyNode(b.root);
    }

    // Destructor
    ~AVLTree() {
        // calls private helper function
        destroy(root);
    }

    // Method to destroy tree
    void timber() {
        // calls private helper function
        destroy(root);
    }

    bool isEmpty() const {
        return (root == nullptr);
    }

    bool find(const Comparable &c) const {
        // calls private helper function
        return find(c, root);
    }

    bool add(const Comparable &c) {
        // calls private helper function
        return add(c, root);
    }

    void remove(const Comparable &c) {
        // calls private helper function
        remove(c, root);
    }

    unsigned long getSize() const {
        return size;
    }

    // Overloaded = operator
    AVLTree& operator = (const AVLTree &rhs) {
        destroy(root);
        size = 0;
        root = copyNode(rhs.root);
    }
};


#endif //PROJECT3STARTER_AVLTREE_H
