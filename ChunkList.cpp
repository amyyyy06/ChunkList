//
// Your code here
//

#include "ChunkList.h"


template<class T>
ChunkList<T>::ChunkList() {
    head = nullptr;
    tail = nullptr;
    iterNode = head;
    arrPos = 0;
    listLen = 0;
    numChunks = 0;

}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {
    if(arrLen < 0)
    {
        throw InvalidArrayLength();
    }
//initialize the iterator to start at the beginning of the list.
    listLen = 0;
    numChunks = 0;


    for(int i = 0; i < arrLen; i++)
    {
        Append(arr[i]);
    }

    iterNode = head;
    arrPos = 0;

}

template<class T>
ChunkList<T>::~ChunkList() { //remove all the nodes in the list.
    Node* current = head;

    while(current != nullptr)
    {
        Remove(current->values[current->len - 1]);

        current = current->next;
    }

}

template<class T>
void ChunkList<T>::Append(T value) {
    if(IsEmpty() || tail->len >= ARRAY_SIZE)
    {
        Node* temp = new Node();
        temp->next = nullptr;
        temp->len = 0;
        temp->values[temp->len++] = value;

        if(IsEmpty())
        {
            head = temp;
        }
        else
        {
            tail->next = temp;
        }

        tail = temp;
        listLen++;
        numChunks++;
    }
    else
    {
        tail->values[tail->len++] = value;
        listLen++;
    }

}

template<class T>
void ChunkList<T>::Remove(T value) {
    if(IsEmpty())
    {
        throw EmptyList();
    }
    Node* curr = head;
    Node* prev = curr;
    while(curr != nullptr)
    {
        for(int i = 0; i < curr->len; i++)
        {
            if(curr->values[i] == value) // if the value is found
            {
                curr->len--;
                listLen--;

                if(curr->len == 0)
                {
                    if(!IsEmpty())
                    {
                        if(curr == head)
                        {
                            head = head->next;
                        }
                        else if(curr == tail)
                        {
                            tail = prev;
                        }
                        else
                        {
                            prev->next = curr->next;
                        }
                    }
                    else
                    {
                        head = nullptr;
                        tail = nullptr;
                    }

                    delete curr;
                    numChunks--;
                }
                else
                {
                    for(int j = i; j < curr->len; j++)
                    {
                        curr->values[j] = curr->values[j + 1];
                    }
                }

                return;
            }
        }

        prev = curr;
        curr = curr->next;
    }


}

template<class T>
int ChunkList<T>::GetLength() {
//return the length of the entire list
    return listLen;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    if(IsEmpty())
    {
        throw EmptyList();
    }

    return (double)listLen / (double)(numChunks * ARRAY_SIZE);
}

template<class T>
bool ChunkList<T>::Contains(T value) {

    if (!head) { //if the list is empty
        throw EmptyList();
    }
//check the array of each node until you find value or you reach the end of the list without finding value
    Node* current = head;
    while (current != nullptr) {
        for (int i = 0; i < current->len; i++) {
            if (current->values[i] == value) {
                return true;
            }
        }
        current = current->next;
    }
    return false;



}

template<class T>
T ChunkList<T>::GetIndex(int i) { //returns the value at index i with reference to the entire list.
    if(IsEmpty()) {
        throw EmptyList();
    }

    if(i < 0 || i >= listLen) //if you provide a bad index.
    {
        throw IndexOutOfBounds();
    }

    Node* curr = head;
    while(curr != nullptr) {
        if(i < curr->len) {
           // return curr->values[i]; //i is within the curr node array and we can return the element
           break;
        }

        i -= curr->len;
        curr = curr->next;
    }
    return curr->values[i];

}

template<class T>
void ChunkList<T>::ResetIterator() {

    iterNode = head; //to the first node of the list
    arrPos = 0;  //to point to the first index.


}

template<class T>
T ChunkList<T>::GetNextItem() {
    if(arrPos >= listLen) //if the user tries to get another item and no item is available.
    {
        throw IteratorOutOfBounds();
    }
    int localIndex = arrPos;

    Node* curr = head;
    while(curr != iterNode)
    {
        localIndex -= curr->len;
        curr = curr->next;
    }

    if(localIndex >= curr->len)
    {
        localIndex = 0;
        iterNode = iterNode->next;
        curr = iterNode;
    }

    arrPos++;
    return iterNode->values[localIndex];
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    return listLen == 0;
    //return head == nullptr;
   // return false;
}

