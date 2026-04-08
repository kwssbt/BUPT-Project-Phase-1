bool EnQueue(Deque deque, QElemSet x){
  if((deque->rear+1)%deque->capacity==deque->front){
    return 0;
  }
  deque->front=(deque->front-1+deque->capacity)%deque->capacity;
  deque->data[deque->front]=x;
  return 1;
}
QElemSet DeQueue(Deque deque){
  if(deque->front==deque->rear){
    return ERROR;
  }
  QElemSet val=deque->data[deque->front];
  deque->front=(deque->front+1)%deque->capacity;
  return val;
}
bool Inject(Deque deque, QElemSet x){
  if((deque->rear+1)%deque->capacity==deque->front){
    return 0;
  }
  deque->data[deque->rear]=x;
  deque->rear=(deque->rear+1)%deque->capacity;
  return 1;
}
QElemSet Eject(Deque deque){
  if(deque->front==deque->rear){
    return ERROR;
  }
  deque->rear=(deque->rear-1+deque->capacity)%deque->capacity;
  return deque->data[deque->rear];
}