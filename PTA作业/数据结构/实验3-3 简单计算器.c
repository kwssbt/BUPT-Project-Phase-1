#include<stdio.h>

int main(){
  int st[1005];
  char st2[1005];
  int top=-1;
  int top2=-1;

  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    int num;
    scanf("%d",&num);
    st[++top]=num;
  }
  for(int i=1;i<n;++i){
    char op;
    scanf(" %c",&op);
    st2[++top2]=op;
  }
  for(int i=1;i<n;++i){
    char op=st2[top2--];
    int a=st[top--];
    int b=st[top--];
    if(op=='+'){
      st[++top]=a+b;
    }
    else if(op=='-'){
      st[++top]=b-a;
    }
    else if(op=='*'){
      st[++top]=b*a;
    }
    else{
      if(a==0){
        printf("ERROR: %d/0",b);
        return 0;
      }
      st[++top]=b/a;
    }
  }
  printf("%d",st[top]);
  
}