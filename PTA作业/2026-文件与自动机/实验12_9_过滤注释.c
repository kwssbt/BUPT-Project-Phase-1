#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(){
  char ch;
  int op=0;
  while(ch=getchar()){
    if(ch=='$')break;
    if(op==0){
      if(ch=='/'){
        op=1;
      }
      else{
        putchar(ch);
      }
    }
    else if(op==1){
      if(ch=='/'){
        op=2;
      }
      else if(ch=='*'){
        op=3;
      }
      else{
        putchar('/');
        putchar(ch);
        op=0;
      }
    }
    else if(op==2){
      if(ch=='\n'){
        putchar('\n');
        op=0;
      }
    }
    else if(op==3){
      if(ch=='*'){
        op=4;
      }
    }
    else{
      if(ch=='/'){
        op=0;
      }
      else if(ch!='*'){
        op=3;
      }
    }
  }
}