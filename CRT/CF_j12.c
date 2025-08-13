#include<stdio.h>

int main(){
  int x,y,z;
  x=y=z=10<<1;
  y=y>>1^3;
  printf("%d %d",x,y);
}