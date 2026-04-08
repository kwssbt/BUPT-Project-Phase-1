#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE*fin=fopen("in.txt","r");
  FILE*fout=fopen("out.txt","w");
  
  int a=0,b=0,c=0,d=0;
  int cnt_line=0;
  int cur_line=0;
  int max_line=-1;
  int min_line=1e9;
  int cnt_A[26]={0};
  int cnt_a[26]={0};

  int ch;
  while((ch=fgetc(fin))!=EOF){
    if(ch>='A'&&ch<='Z'){
      a++;
      cnt_A[ch-'A']++;
    }
    else if(ch>='a'&&ch<='z'){
      b++;
      cnt_a[ch-'a']++;
    }
    else if(ch>='0'&&ch<='9'){
      c++;
    }
    else{
      d++;
    }

    if(ch=='\n'){
      if(max_line<cur_line)max_line=cur_line;
      if(min_line>cur_line)min_line=cur_line;
      cur_line=0;
      cnt_line++;
    }
    else{
      cur_line++;
    }
  }

  fprintf(fout,"Task1:\n");
  fprintf(fout,"capital: %d\n",a);
  fprintf(fout,"lowercase: %d\n",b);
  fprintf(fout,"digit: %d\n",c);
  fprintf(fout,"others: %d\n",d);

  fprintf(fout,"Task2:\n");
  fprintf(fout,"line: %d\n",cnt_line);
  fprintf(fout,"%d characters in max line.\n",max_line);
  fprintf(fout,"%d characters in min line.\n",min_line);
  
  fprintf(fout,"Task3:\n");
  fprintf(fout,"CAPITAL:\n");
  for(int i='A';i<='Z';++i){
    fprintf(fout,"%c:%d\n",i,cnt_A[i-'A']);
  }
  fprintf(fout,"LOWERCASE:\n");
  for(int i='a';i<='z';++i){
    fprintf(fout,"%c:%d\n",i,cnt_a[i-'a']);
  }

  fclose(fin);
  fclose(fout);
}