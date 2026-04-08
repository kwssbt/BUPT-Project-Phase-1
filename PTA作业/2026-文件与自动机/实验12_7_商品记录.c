#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    char name[32];
    int amount;
    double price;
}GOOD;

int main(){
  int ID[10];

  FILE*fp=fopen("in.dat","rb");

  fread(ID,sizeof(int),10,fp);
  for(int i=0;i<10;++i){
    GOOD good;
    fseek(fp,sizeof(ID)+sizeof(GOOD)*(ID[i]-1),SEEK_SET);
    fread(&good,sizeof(GOOD),1,fp);
    printf("%d %s %d %.2lf\n",good.id,good.name,good.amount,good.price);
  }

  fclose(fp);
}
