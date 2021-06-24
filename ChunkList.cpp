//
// Your code here
//

#include "ChunkList.h"


template<class T>
ChunkList<T>::ChunkList() {
    head = nullptr;
    tail = nullptr;
    arrPos = 0;
    listLen = 0;
    numChunks = 0;

/*
   Node* tmpNode;

   while(head != nullptr){
       tmpNode=head;
       delete tmpNode;
   }
    listLen = 0;
*/

}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {



    if(arrLen<0){
        throw InvalidArrayLength ();
    }

}

template<class T>
ChunkList<T>::~ChunkList() {
    Node*tmpNode;

    while(head !=nullptr){
        tmpNode = head;
        head = head->next;
        delete tmpNode;
    }

}

template<class T>
void ChunkList<T>::Append(T value) {

   // Node* location = new Node; // new node address created
   // location -> values= value; //set all the values of the node
   // location -> next = head;  //set all the values of the node
   // head = location;
   // listLen++;  //book keeping
   //Node*curr= head;//

   //head-> next, head->values //only know

    Node* position = head;
    while(position != nullptr){
        for(int i = 0; i < 8; i++){
            if(position->values == nullptr){
                position -> values[i]= value;
                position -> next = tail;
                tail = position;

            }
            else if(position ->values != nullptr){
                Node* location = new Node;
                location -> values[i]= value;
                location -> next = head;
                head = location;
            }

        }

        listLen++;

    }










}

template<class T>
void ChunkList<T>::Remove(T value) {
    Node*prev = nullptr;
    Node*curr = head;
    while(curr!=nullptr) {  //middle case
        // finds the location of the node we want
        if (curr->values == &value) {
           // prev->next = curr->next;
            listLen--;
            //delete curr;
            break;
        }
       // prev = curr;
       // curr = curr->next;
        curr = prev;
        prev = prev->next;

       // listLen--;
    }
    if(prev == nullptr){
        head = curr->next;
        delete curr;
    }
    else if(curr != nullptr){
        prev->next= curr->next;
        delete curr;
    }
    if(IsEmpty()){
        throw EmptyList();
    }


    /*
     * int location = 0;
     * for (location=0; location<length; location+1){
         if(values[location]==value)
         break;
         }
         for (int 1= location; i<length-1;i++){
         values[i]=values[i+1];

         }
         length--;
     */



}

template<class T>
int ChunkList<T>::GetLength() {

    return listLen;
}

template<class T>
double ChunkList<T>::LoadFactor() {

    //load_factor = listLen/(ARRAY_SIZE*numChunks);

    if(IsEmpty()){
        throw EmptyList();
    }
    return 0;
}

template<class T>
bool ChunkList<T>::Contains(T value) {


  // keep track where i am
    Node* curr = head;  //memory



    while(curr != nullptr){
        for(int i = 0; i<ARRAY_SIZE; i++ ){
            if(curr -> values == &value){
                return true;
            }
            curr = curr -> next; // move to next node

        }

    }

    if(IsEmpty()){
        throw EmptyList();
    }


    return false;

}

template<class T>
T ChunkList<T>::GetIndex(int i) {
  //  return NULL;

    if(IsEmpty()){
        throw EmptyList();
    }

    if(i<0){
        throw IndexOutOfBounds();
    }



}

template<class T>
void ChunkList<T>::ResetIterator() {
   // Node* iterNode;     // What node are were currently on?
   // int arrPos;
   //arrPos = ;
    iterNode = head;
   // Node*arrPos= nullptr;



  // arrPos = head;
  /*
    iterNode = head;
    arrPos = 0;
*/




}

template<class T>
T ChunkList<T>::GetNextItem() {
   // Node* iterNode;     // What node are were currently on?
   // int arrPos;
   // return NULL;


  // T currItem = arrPos -> value; // current item
  //  arrPos = arrPos-> next;    // move curPos to next node
 //  return currItem;


  //  T currItem = iterNode -> values;
 //   iterNode = iterNode-> next;
 //   return currItem;

 //  if(!currItem){
//       throw IteratorOutOfBounds();
  // }
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    return false;
}

