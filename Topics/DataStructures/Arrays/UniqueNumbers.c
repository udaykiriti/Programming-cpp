#include<stdio.h>

int UniqueDigits(int n){
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
      if(arr[i] == arr[j]) a++;
    }
    if(a==1)
      uc++;
  }
  return uc;
}


int UniqueNumbers(int arr[],int n){
  if(n==1) return arr[0];
  int max=0,uc,result,i;
  for(int i=0;i<n;i++){
    uc=UniqueDigits(arr[i]);
    if(uc > max){
      max = uc;
      result = arr[i];
    }
  }
  return result;
}


int main(){
  int n; scanf("%d", &n);
  int arr[n];
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  int c=UniqueNumbers(arr, n);
  printf("%d\n", c);
  return 0;
}