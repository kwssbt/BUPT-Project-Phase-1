LISTNODEPTR createListHead(){
  LISTNODE*h=(LISTNODE*)malloc(sizeof(LISTNODE));
  h->nextPtr=NULL;
  return h;
}
void createList(LISTNODEPTR headPtr){
  char n[100];
  LISTNODE*p=headPtr;
  while(scanf("%s",n)==1&&strcmp(n,"-1")!=0){
    LISTNODE*node=(LISTNODE*)malloc(sizeof(LISTNODE));
    node->data=n[0];
    node->nextPtr=NULL;
    p->nextPtr=node;
    p=p->nextPtr;
  }
}

void split(LISTNODEPTR headPtr , LISTNODEPTR La , LISTNODEPTR Lb , LISTNODEPTR Lc){
  LISTNODE*p=headPtr->nextPtr;
  headPtr->nextPtr=NULL;
  while(p!=NULL){
    LISTNODE*q;
    char c=p->data;
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
      q=La;
    }
    else if(c>='0'&&c<='9'){
      q=Lb;
    }
    else{
      q=Lc;
    }
    while(q->nextPtr!=NULL&&q->nextPtr->data<c){
      q=q->nextPtr;
    }
    LISTNODE*nex=p->nextPtr;
    p->nextPtr=q->nextPtr;
    q->nextPtr=p;
    p=nex;
  }
}