LISTNODEPTR createListHead(){
  LISTNODE*h=(LISTNODE*)malloc(sizeof(LISTNODE));
  h->nextPtr=NULL;
  return h;
}
void createList(LISTNODEPTR headPtr){
  int n;
  LISTNODE*p=headPtr;
  while(scanf("%d",&n)==1&&n!=-1){
    LISTNODE*node=(LISTNODE*)malloc(sizeof(LISTNODE));
    node->data=n;
    node->nextPtr=NULL;
    p->nextPtr=node;
    p=p->nextPtr;
  }
}

void mergeSortList(LISTNODEPTR headPtr1, LISTNODEPTR headPtr2){
  LISTNODE*pre1=headPtr1;
  LISTNODE*p1=pre1->nextPtr;
  LISTNODE*pre2=headPtr2;
  LISTNODE*p2=pre2->nextPtr;
  while(p1!=NULL&&p2!=NULL){
    if(p1->data==p2->data){
      pre1=p1;
      p1=p1->nextPtr;
      pre2=p2;
      p2=p2->nextPtr;
      continue;
    }
    if(p1->data<p2->data){
      pre1=p1;
      p1=p1->nextPtr;
    }
    else{
      LISTNODE*p2nex=p2->nextPtr;
      pre2->nextPtr=p2nex;
      pre1->nextPtr=p2;
      pre1=p2;
      p2->nextPtr=p1;
      p2=p2nex;
    }
  }
  if(p1==NULL&&p2!=NULL){
    pre1->nextPtr=p2;
    pre2->nextPtr=NULL;
  }
}
