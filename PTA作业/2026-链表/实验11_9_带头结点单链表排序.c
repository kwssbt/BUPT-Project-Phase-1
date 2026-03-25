LISTNODEPTR createListHead(){
  LISTNODE*h=(LISTNODE*)malloc(sizeof(LISTNODE));
  h->nextPtr=NULL;
  return h;
}

void listSortiing(LISTNODEPTR headPtr){
  if(headPtr==NULL)return;
  LISTNODE*p=headPtr;
  int v;
  while(scanf("%d",&v)==1&&v!=-1){
    LISTNODE*node=(LISTNODE*)malloc(sizeof(LISTNODE));
    node->data=v;
    node->nextPtr=NULL;
    p->nextPtr=node;
    p=node;
  }
  if(headPtr==NULL||headPtr->nextPtr==NULL||headPtr->nextPtr->nextPtr==NULL)return;
  LISTNODE* curr=headPtr->nextPtr->nextPtr; 
    headPtr->nextPtr->nextPtr=NULL; 
    while(curr!=NULL){
        LISTNODE*nextNode=curr->nextPtr; 
        LISTNODE*prev=headPtr;
        while(prev->nextPtr!=NULL&&prev->nextPtr->data<=curr->data){
            prev=prev->nextPtr;
        }
        curr->nextPtr=prev->nextPtr;
        prev->nextPtr=curr;
        curr=nextNode;
    }
}
