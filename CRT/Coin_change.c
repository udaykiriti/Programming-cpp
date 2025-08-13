#include<stdio.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define EXIT return 0

int solveCC(int arr[],int n,int s){
  if(s==0) return 1;
  if(s<0|| n<=0) return 0;
  return solveCC(arr,n,s-arr[n-1]) + solveCC(arr,n-1,s);
}

int main(int argc, char *argv[]){
  int n,s;
  scanf("%d",&n);
  int arr[n];
  FOR(i,0,n) scanf("%d",&arr[i]);
  scanf("%d",&s);
  int X=solveCC(arr,n,s);
  printf("%d\n",X);
  EXIT;
}