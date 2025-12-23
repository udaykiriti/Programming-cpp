/*
#include<stdio.h>
int main(){
  int g,r; scanf("%d",&g);
  if(g<=0) r=0;
  else if(g<=20) r=5;
  else if((g-20)%10==0) r=5+(g-20)/10*5;
  else r=5+5+(g-20)/10*5;
  printf("%d",r);
  return 0;  
}
*/

#include <stdio.h>
#include <stdbool.h>

bool unique(int n) {
    int a[10] = {0}; 
    while (n) {
        int r = n % 10;
        if (a[r]) return false;
        a[r] = 1;
        n /= 10;
    }
    return true;
}

int main() {
    int s, e;
    scanf("%d %d", &s, &e);
    int found = 0;
    for (int i = s; i <= e; i++) {
        if (unique(i)) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) printf("-1");
    return 0;
}