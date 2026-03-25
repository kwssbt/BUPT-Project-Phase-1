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
int    match(LISTNODEPTR headPtr1 , LISTNODEPTR headPtr2){
  LISTNODE *p,*q,*t;
  for(p=headPtr1->nextPtr;p!=NULL;p=p->nextPtr){
    int f=1;
    for(q=headPtr2->nextPtr,t=p;q!=NULL;q=q->nextPtr,t=t->nextPtr){
      if(t==NULL||t->data!=q->data){
        f=0;
        break;
      }
    }
    if(f==1){
      return 1;
    }
  }
  return 0;
}
