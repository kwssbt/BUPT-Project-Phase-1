List Delete( List list, ElemSet min_value, ElemSet max_value ){
  int p=0;
  for(int i=0;i<=list->last;++i){
    if(list->data[i]<=min_value||list->data[i]>=max_value){
      list->data[p++]=list->data[i];
    }
  }
  list->last=p-1;
  return list;
}