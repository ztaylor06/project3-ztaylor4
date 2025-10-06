#ifndef PROJECT3STARTER_SPLAYTREE_H
#define PROJECT3STARTER_SPLAYTREE_H


template <typename Comparable>
class SplayTree {
private:
    struct SplayNode {
        Comparable value;
        SplayNode* leftChild;
        SplayNode* rightChild;
        SplayNode* parent;

        // Constructors
        SplayNode() : value(Comparable()), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
        explicit SplayNode(Comparable c) : value(c), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
        SplayNode(Comparable c, SplayNode* l, SplayNode* r, SplayNode* p = nullptr) : value(c), leftChild(l), rightChild(r), parent(p) {}
    };
    SplayNode* root;
    unsigned long size;

    // Helper recursive function to destroy the tree.
    void destroy(SplayNode* &n) {
        if (n != nullptr) {
            destroy(n->leftChild);
            destroy(n->rightChild);
            delete n;
            n = nullptr;
        }
    }

    // Helper recursive function to copy the tree.
    SplayNode* copyNode(SplayNode* n) {
        if (n == nullptr) {
            return nullptr;
        }
        ++size;
        return new SplayNode(n->value, copyNode(n->leftChild), copyNode(n->rightChild), n->parent);
    }

    // Helper method to perform a single right rotation.
    SplayNode* singleRotationRightFromChild(SplayNode* n) {
        // n has to move up,
        // n's parent has to move down to the right.
        n->parent->leftChild = n->rightChild;
        if (n->rightChild != nullptr) {
            n->rightChild->parent = n->parent;
        }
        n->rightChild = n->parent;
        n->parent = n->rightChild->parent;
        if (n->rightChild->parent != nullptr) {
            // don't know if n's original parent was a left or right child
            if (n->rightChild->parent->leftChild == n->rightChild) {
                n->rightChild->parent->leftChild = n;
            } else {
                n->rightChild->parent->rightChild = n;
            }
        }
        n->rightChild->parent = n;
        if (n->rightChild == root) {
            root = n;
        }

        return n;
    }

    // Helper method to perform a single left rotation.
    SplayNode* singleRotationLeftFromChild(SplayNode* n) {
        // n has to move up,
        // n's parent has to move down to the left.
        n->parent->rightChild = n->leftChild;
        if (n->leftChild != nullptr) {
            n->leftChild->parent = n->parent;
        }
        n->leftChild = n->parent;
        n->parent = n->leftChild->parent;
        if (n->leftChild->parent != nullptr) {
            // don't know if n's original parent was a left or right child
            if (n->leftChild->parent->leftChild == n->leftChild) {
                n->leftChild->parent->leftChild = n;
            } else {
                n->leftChild->parent->rightChild = n;
            }
        }
        n->leftChild->parent = n;
        if (n->leftChild == root) {
            root = n;
        }

        return n;
    }

    // Method that will move a node higher in the tree
    void splay(SplayNode* n) {
        if (n->parent == nullptr) {
            // n is root. Nothing to do.
            return;
        }
        else if (n->parent->leftChild == n && n->parent->parent == nullptr) {
            // n is left child of root. Need single rotation to the right.
            singleRotationRightFromChild(n);
            return;
        }
        else if (n->parent->rightChild == n && n->parent->parent == nullptr) {
            // n is right child of root. Need single rotation to the left.
            singleRotationLeftFromChild(n);
            return;
        }
        else if (n->parent->leftChild == n && n->parent->parent->leftChild == n->parent) {
            // left-left case. Need to see-saw to the right.
            n = singleRotationRightFromChild(n->parent);
            n = singleRotationRightFromChild(n->leftChild);
        }
        else if (n->parent->rightChild == n && n->parent->parent->rightChild == n->parent) {
            // right-right case. Need to see-saw to the left.
            n = singleRotationLeftFromChild(n->parent);
            n = singleRotationLeftFromChild(n->rightChild);
        }
        else if (n->parent->leftChild == n && n->parent->parent->rightChild == n->parent) {
            // grandparent-to-n right-left case. Need a double rotation (right-left).
            n = singleRotationRightFromChild(n);
            n = singleRotationLeftFromChild(n);
        }
        else if (n->parent->rightChild == n && n->parent->parent->leftChild == n->parent) {
            // grandparent-to-n left-right case. Need a double rotation (left-right).
            n = singleRotationLeftFromChild(n);
            n = singleRotationRightFromChild(n);
        }
        if (n != root) {
            splay(n);
        }
    }

    // Helper recursive function to find a value in the tree.
    bool find(const Comparable &c, SplayNode* &n) {
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
        splay(n);
        return true;
    }

    // Helper recursive function to add a value to the tree.
    bool add(const Comparable &c, SplayNode* &n, SplayNode* p) {
        if (n == nullptr) {
            // We found the place where we can add the node.
            n = new SplayNode(c, nullptr, nullptr, p);
            ++size;
            splay(n);
            return true;
        }
        else if (c < n->value) {
            // Value is less than current node. Go to left child.
            return add(c, n->leftChild, n);
        }
        else if (n->value < c) {
            // Value is greater than current node. Go to right child.
            return add(c, n->rightChild, n);
        }
        // If code reaches here, value is a duplicate. Cannot add it to the tree.
        return false;
    }

    // Helper recursive method to find the maximum value from a given node.
    Comparable& findMax(SplayNode* n) {
        if (n->rightChild == nullptr) {
            return n->value;
        }
        return findMax(n->rightChild);
    }

    // Helper recursive function to delete a value from the tree.
    void remove(const Comparable &c, SplayNode* &n) {
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
            SplayNode *oldNode = n;
            n = (n->leftChild != nullptr) ? n->leftChild : n->rightChild;
            delete oldNode;
            oldNode = nullptr;
            --size;
        }
    }

public:
    // Default Constructor
    SplayTree() {
        root = nullptr;
        size = 0;
    }

    // Copy Constructor
    SplayTree(const SplayTree &b) {
        size = 0;
        // calls private helper function
        root = copyNode(b.root);
    }

    // Destructor
    ~SplayTree() {
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

    bool find(const Comparable &c) {
        // calls private helper function
        return find(c, root);
    }

    bool add(const Comparable &c) {
        // calls private helper function
        return add(c, root, nullptr);
    }

    void remove(const Comparable &c) {
        // calls private helper function
        remove(c, root);
    }

    unsigned long getSize() const {
        return size;
    }

    // Overloaded = operator
    SplayTree& operator = (const SplayTree &rhs) {
        destroy(root);
        size = 0;
        root = copyNode(rhs.root);
    }
};


#endif //PROJECT3STARTER_SPLAYTREE_H
