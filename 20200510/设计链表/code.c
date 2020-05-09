


typedef struct MyLinkedList{
    int value;
    struct MyLinkedList * nextPtr;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList * head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->nextPtr = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList * curNode = NULL;
    curNode = obj->nextPtr;
    while(index>0 && curNode->nextPtr != NULL) {
      curNode = curNode->nextPtr;
      index--;
    }
    if(index > 0) {
        return -1;
    }
    return curNode->value;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  MyLinkedList * head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  head->value = val;
  head->nextPtr = obj->nextPtr;
  obj->nextPtr = head;
  return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
      MyLinkedList * cur = (MyLinkedList *)malloc(sizeof(MyLinkedList));
      MyLinkedList * tail = obj;
      while(tail->nextPtr != NULL) {
          tail = tail->nextPtr;
      }
      cur->value = val;
      cur->nextPtr = NULL;
      tail->nextPtr = cur;
      return obj;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList * cur = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    MyLinkedList * curNode = NULL;
    curNode = obj;
    while(index>0 && curNode->nextPtr != NULL) {
      curNode = curNode->nextPtr;
      index--;
    } 
    if(index > 0) {
        return;
    }

    cur->value = val;
    cur->nextPtr = curNode->nextPtr;
    curNode->nextPtr = cur;
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList * curNode = NULL;
    MyLinkedList * preNode = NULL;
    if(obj == NULL) {
        return;
    }
    curNode = obj->nextPtr;
    if(index == 0) {
        obj->nextPtr = curNode->nextPtr;
        free(curNode);
        return;
    }

    while(index>0 && curNode->nextPtr != NULL) {
      preNode = curNode;
      curNode = curNode->nextPtr;
      index--;
    }
    if(index > 0) {
        return;
    }  
    preNode->nextPtr = curNode->nextPtr;
    free(curNode);
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
      MyLinkedList * tail = obj;
      MyLinkedList * preNode = NULL;
      while(tail->nextPtr != NULL) {
          preNode = tail;
          tail = tail->nextPtr;
          free(preNode);
      }    
      free(tail);
      return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/