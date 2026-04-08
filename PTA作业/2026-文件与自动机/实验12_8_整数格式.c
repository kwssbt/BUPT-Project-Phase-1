#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool check(const char*s){
  int len=strlen(s);
  if(len==0)return 0;
  if(s[0]=='0'&&len==1)return 1;
  if(s[0]=='-'||s[0]=='+'){
    if(len==1)return 0;
    if(s[1]=='0')return 0;
    for(int i=1;i<len;++i){
      if(s[i]<'0'||s[i]>'9')return 0;
    }
    return 1;
  }
  else{
    if(s[0]=='0')return 0;
    for(int i=0;i<len;++i){
      if(s[i]<'0'||s[i]>'9')return 0;
    }
    return 1;
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    char s[35];
    scanf("%s",s);
    if(check(s)){
      printf("yes\n");
    }    
    else{
      printf("no\n");
    }
  }
}