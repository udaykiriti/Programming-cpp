#include<stdio.h>
void Squares(int n){
  if(n == 0) return;
  Squares(n - 1);
  printf("%d ", n * n);
}
int main(){
  int n; 
  scanf("%d", &n);
  Squares(n); 
  return 0;
}