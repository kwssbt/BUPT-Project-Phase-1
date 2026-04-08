#include<stdio.h>
#include<stdlib.h>

int main(){
  int N;
  scanf("%d",&N);
  int q[1000005];
  int f=0,r=0;
  for(int i=0;i<N;++i){
    int id;
    scanf("%d",&id);
    q[r++]=id;
  }
  int ans=0;
  double sum=0;
  int tar=1;
  while(f<r){
    ans++;
    if(q[f]!=tar){
      q[r++]=q[f];
    }
    else{
      sum+=ans;
      tar++;
    }
    f++;
  }
  printf("%d %.1lf",ans,sum/N);
}