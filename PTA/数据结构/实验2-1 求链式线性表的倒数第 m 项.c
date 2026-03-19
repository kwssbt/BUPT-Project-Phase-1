ElemSet Find( List list, int m ){
  int cnt=0;
  List p=list;
  while(p!=NULL){
    cnt++;
    p=p->next;
  }
  int k=cnt-m;
  if(k<1){
    return ERROR;
  }
  p=list;
  while(k--)p=p->next;
  return p->data;
}