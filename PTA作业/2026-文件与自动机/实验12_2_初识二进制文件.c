#include<stdio.h>
#include<stdlib.h>

int main(){
  char a,aa[5];
  short b,bb[5];
  int c,cc[5];
  long d,dd[5];
  long long e,ee[5];
  float g,gg[5];
  double h,hh[5];

    FILE*fp=fopen("in.dat","rb");

    fread(&a,sizeof(a),1,fp);
    fread(&b, sizeof(b), 1, fp);
    fread(&c, sizeof(c), 1, fp);
    fread(&d, sizeof(d), 1, fp);
    fread(&e, sizeof(e), 1, fp);
    fread(&g, sizeof(g), 1, fp);
    fread(&h, sizeof(h), 1, fp);
    fread(aa, sizeof(a), 5, fp);
    fread(bb, sizeof(b), 5, fp);
    fread(cc, sizeof(c), 5, fp);
    fread(dd, sizeof(d), 5, fp);
    fread(ee, sizeof(e), 5, fp);
    fread(gg, sizeof(g), 5, fp);
    fread(hh, sizeof(h), 5, fp);

    fclose(fp);

    printf("%c\n", a);
    printf("%hd\n", b);
    printf("%d\n", c);
    printf("%ld\n", d);
    printf("%lld\n", e);
    printf("%f\n", g);
    printf("%lf\n", h);

    printf("%s\n",aa);
    for(int i=0;i<5;++i){
      printf("%hd",bb[i]);
      if(i==4)printf("\n");
      else printf(" ");
    }
    for(int i=0;i<5;++i){
      printf("%d",cc[i]);
      if(i==4)printf("\n");
      else printf(" ");
    }
    for(int i=0;i<5;++i){
      printf("%ld",dd[i]);
      if(i==4)printf("\n");
      else printf(" ");
    }
    for(int i=0;i<5;++i){
      printf("%lld",ee[i]);
      if(i==4)printf("\n");
      else printf(" ");
    }
    for(int i=0;i<5;++i){
      printf("%f",gg[i]);
      if(i==4)printf("\n");
      else printf(" ");
    }
    for(int i=0;i<5;++i){
      printf("%lf",hh[i]);
      if(i==4)printf("\n");
      else printf(" ");
    }
}