#include<stdio.h>

int main(){
  int st[105];
  int top=-1;
  
  char s[1005];
  while(fgets(s,sizeof(s),stdin)){

    if(s[0]=='.'&&s[1]=='\n')break;
    
  for(int i=0;s[i]!='\0';++i){
    if(s[i]=='/'&&s[i+1]=='*'){
      st[++top]=1;
      ++i;
    }
    else if(s[i]=='('){
      st[++top]=2;
    }
    else if(s[i]=='['){
      st[++top]=3;
    }
    else if(s[i]=='{'){
      st[++top]=4;
    }
    else if((s[i]=='*'&&s[i+1]=='/')||s[i]==')'||s[i]==']'||s[i]=='}'){
      int val;
      if(s[i]=='*'&&s[i+1]=='/'){
        val=-1;
        ++i;
      }
      else if(s[i]==')'){
        val=-2;
      }
      else if(s[i]==']'){
        val=-3;
      }
      else{
        val=-4;
      }

      if(top==-1){
        printf("NO\n");
        if(val==-1)printf("?-*/");
        if(val==-2)printf("?-)");
        if(val==-3)printf("?-]");
        if(val==-4)printf("?-}");
        return 0;
      }
      if(val+st[top]!=0){
        printf("NO\n");
        if(st[top]==1)printf("/*-?");
        if(st[top]==2)printf("(-?");
        if(st[top]==3)printf("[-?");
        if(st[top]==4)printf("{-?");
        return 0;
      }
      --top;
    }
  }
  }
  if(top==-1){
    printf("YES");
  }
  else{
    printf("NO\n");
    if(st[top]==1)printf("/*-?");
    if(st[top]==2)printf("(-?");
    if(st[top]==3)printf("[-?");
    if(st[top]==4)printf("{-?");
  }
}