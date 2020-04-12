


typedef struct {
    int deepth;
    int start;
    int end;    
    int * value;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->deepth = k+1;
    queue->start = 0;
    queue->end = 0;
    queue->value = (int *)malloc(sizeof(int)*(k+1));
    memset(queue->value,0,sizeof(int)*(k+1));
    return queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if( obj->start == (obj->end+1)% obj->deepth){
      return false;
  } else {
      obj->end = (obj->end + 1)% obj->deepth;
      obj->value[obj->end % obj->deepth] = value;
      return true;
  }
  return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if((obj->start%obj->deepth) == obj->end){
      return false;
  } else {
      obj->start = (obj->start + 1)% obj->deepth;
      return true;
  }
  return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
 if((obj->start%obj->deepth) == obj->end){
      return -1;
  } else {
      return obj->value[(obj->start + 1)% obj->deepth];
  }
  return -1;  
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
 if((obj->start%obj->deepth) == obj->end){
      return -1;
  } else {
      return obj->value[obj->end % obj->deepth];
  }
  return -1; 
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if((obj->start%obj->deepth) == obj->end){
      return true;
  } else {
      false;
  }
  return false;   
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  if((obj->end + 1)%obj->deepth == obj->start){
      return true;
  } else {
      false;
  }
  return false;   
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->value);
    free(obj);
    return;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/