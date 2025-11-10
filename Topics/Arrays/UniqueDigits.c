#include<stdio.h>
int uniqueDigit(int n){
  int i,j,k=0,uc=0,a,digit,temp=n;
  int arr[10];
  while(n>0){
    digit = n%10;
    arr[k++] = digit;
    n = n/10;
  }
  for(i=0;i<k;i++){
    a =0;
    for(j=0;j<k;j++){
      if(arr[i] == arr[j]){
        a++;
      }
    }
    if(a==1){
      uc++;
    }
  }
  return uc;
}
int main(){
  int n;
  scanf("%d",&n);
  if(n>=0 && n<=9){
    printf("1");
  }else{
    int c = uniqueDigit(n);
    printf("%d",c);
  }
  return 0;
}