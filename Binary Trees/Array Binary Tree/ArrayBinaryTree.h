#ifndef ARRAYBINARYTREE_H
#define ARRAYBINARYTREE_H

template <typename T>
class ArrayBinaryTree
{
    int maxHeight;
    int arraySize;
    T* nodes;
    bool* nodesStatus;

    void VLR(int);
    void LRV(int);
    void LVR(int);
    int search(int, T);
    void Delete(int);

public:
    ArrayBinaryTree(int);
    void setRoot(T);
    int searchNode(T key) { return search(0, key); }
    void inOrder() { LVR(0); }
    void preOrder() { VLR(0); }
    void postOrder() { LRV(0); }
    void setLeftChild(T, T);
    void setRightChild(T, T);
    void setParent(T, T);
    T getLeftChild(T);
    T getRightChild(T);
    T getRoot() { return nodes[0]; }
    void printAncestors(T);
    void printDescendents(T);
    int getHeight(int);
    int getTreeHeight() { return getHeight(0); }
    void remove(T);
    T getParent(T);
    ~ArrayBinaryTree();
};


#endif // !ARRAYBINARYTREE_H

