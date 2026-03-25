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
void exchange(LISTNODEPTR headPtr , int s1 , int t1 , int s2 , int t2){
  LISTNODE *l0,*l1,*r1,*l2,*r2,*l3,*r3,*l4;
  LISTNODE *p;
  int k;
  
  p=headPtr;
  k=s1-1;
  while(k--)p=p->nextPtr;
  l0=p;
  l1=p->nextPtr;

  p=headPtr;
  k=t1;
  while(k--)p=p->nextPtr;
  r1=p;
  l2=p->nextPtr;

  p=headPtr;
  k=s2-1;
  while(k--)p=p->nextPtr;
  r2=p;
  l3=p->nextPtr;
  
  p=headPtr;
  k=t2;
  while(k--)p=p->nextPtr;
  r3=p;
  l4=p->nextPtr;
  if(t1+1==s2){
    l0->nextPtr=l3;
    r3->nextPtr=l1;
    r1->nextPtr=l4;
  }
  else{
    l0->nextPtr=l3;
    r3->nextPtr=l2;
    r2->nextPtr=l1;
    r1->nextPtr=l4;
  }
}