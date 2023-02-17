//
// Created by Varick Erickson 2/3/2021.
//

#ifndef CHUNKLIST_CHUNKLIST_H
#define CHUNKLIST_CHUNKLIST_H

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 8;

// These error classes are done. No modifications are required.
// See ChunkList_demo.cpp for an example of how they are used.
class InvalidArrayLength{
public:
    string Msg() {
        return "Invalid array length used for constructor.";
    }
};

class IndexOutOfBounds {
public:
    string Msg() {
        return "Index is out of bounds";
    }
};

class IteratorOutOfBounds {
public:
    string Msg() {
        return "Iterator is out of bounds.  Nothing left to iterate over.";
    }
};

class EmptyList {
public:
    string Msg() {
        return "List is empty";
    }
};

// Put your pre/post conditions here.

template<class T>
class ChunkList {
public:
    // default Constructors
    ChunkList();
    //Pre: node
    //Post: Creates a new, empty ChunkList object.

    //second Constructors
    ChunkList(T arr[], int arrLen);

    // Deconstructor
    ~ChunkList();

    // Add/remove elements
    void Append(T value);
    //Pre: List has been initialized.
    //Post: Added value to the end of the ChunkList.
    void Remove(T value);
    //Pre: the chunkList contains values
    //Post: if the value is found, if it's the last item in a node, delete the node, reallocate the pointers and
    //      decrement numChunks, otherwise, shift all the values in the array by 1 to overwrite the value

    // Stuff to find out about the ChunkList
    int GetLength();
    //Pre: List has been initialized.
    //Post: return Function value = number of items in list.
    double LoadFactor();
    //Pre: chunkList has been initialized.
    //Post: return Calculate a percentage of stored items in the Chunklist.
    bool Contains(T value);
    //Pre: chunkList is defined.
    //Post: If there is a value in the Chunk list return true. Otherwise it will return false. Or go to error.

    // Accessing elements
    T GetIndex(int i);
    //Pre: chunkList is defined.
    //Post: Look the entire list and return the value at index i.
    void ResetIterator();
    //Pre: still items left in the chunkList
    //Post: Array position and interNode are the first position to list.
    T GetNextItem();
    //Pre: List has been initialized.
    //Post: Current item moves to next position.
    bool IsEmpty();
    //Pre: List has been initialized.
    //Post: Function value = (list is empty)
private:

    // Note we did not need to make this a template
    // since this struct is part of a template class.
    struct Node {
        Node* next;
        int len;
        T values[ARRAY_SIZE];
    };

    Node* head;
    Node* tail; 

    // iterator
    Node* iterNode;     // What node are were currently on?
    int arrPos;         // Within the node, what element are we looking at?

    int listLen;        // Total elements
    int numChunks;      // Total chunks/nodes
};
/*
template<class T>
ChunkList<T>::ChunkList() {

}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {

}

template<class T>
ChunkList<T>::~ChunkList() {

}

template<class T>
void ChunkList<T>::Append(T value) {

}

template<class T>
void ChunkList<T>::Remove(T value) {

}

template<class T>
int ChunkList<T>::GetLength() {
    return 0;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    return 0;
}

template<class T>
bool ChunkList<T>::Contains(T value) {
    return false;
}

template<class T>
T ChunkList<T>::GetIndex(int i) {
    return NULL;
}

template<class T>
void ChunkList<T>::ResetIterator() {

}

template<class T>
T ChunkList<T>::GetNextItem() {
    return NULL;
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    return false;
}
*/
#include "ChunkList.cpp"

#endif //CHUNKLIST_CHUNKLIST_H
