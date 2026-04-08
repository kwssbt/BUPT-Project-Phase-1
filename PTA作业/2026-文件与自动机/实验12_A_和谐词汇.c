#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
  FILE*fin=fopen("in.txt","r");
  FILE*fout=fopen("out.txt","w");

  char words[8][10];
  int words_len[8];
  for(int i=0;i<8;++i){
    fgets(words[i],sizeof(words[i]),fin);
    int len=strlen(words[i]);
    words[i][len-1]='\0';
    words_len[i]=len-1;
  }

  char s[111];
  while(fgets(s,sizeof(s),fin)!=NULL){
    int p=0;
    int len=strlen(s);
    while(p<len){
      int id=-1;
      for(int i=0;i<8;++i){
        int j=0;
        while(j<words_len[i]&&s[p+j]==words[i][j])++j;
        if(j==words_len[i]){
          id=i;
          break;
        }
      }

      if(id==-1){
        fputc(s[p],fout);
        p++;
      }
      else{
        fprintf(fout,"%s","!@#$%^&*");
        p+=words_len[id];
      }
    }
  }
  fclose(fin);
  fclose(fout);
}
