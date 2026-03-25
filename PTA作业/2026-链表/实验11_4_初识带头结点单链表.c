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
void listTraverse(LISTNODEPTR headPtr){
  LISTNODE*p=headPtr->nextPtr;
  int m=10000,M=-1,sum=0;
  while(p!=NULL){
    int v=p->data;
    sum+=v;
    if(v>M)M=v;
    if(v<m)m=v;
    p=p->nextPtr;
  }
  printf("The maximum,minmum and the total are:%d %d %d\n",M,m,sum);
}