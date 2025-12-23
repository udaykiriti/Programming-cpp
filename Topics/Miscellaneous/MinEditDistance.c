#include<stdio.h>
#include<string.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int min(int p,int q,int r){
  if(p<=q && p<=r) return p;
  else if(q<=p && q<=r) return q;
  else return r;
}

int solveMED(char s1[],char s2[]){
  int x=strlen(s1);
  int y=strlen(s2);
  int MED[x+1][y+1];
  FOR(r,0,x+1){
    FOR(c,0,y+1){
      if(r==0&&c==0) MED[r][c]=0;
      else if(r==0) MED[r][c]=MED[r][c-1]+1; 
      else if(c==0) MED[r][c]=MED[r-1][c]+1;
      else{
          if(s1[r-1]==s2[c-1]) MED[r][c]=MED[r-1][c-1];
          else MED[r][c]=min(MED[r-1][c],MED[r-1][c-1],MED[r][c-1])+1;
      }
    }
  }
  return MED[x][y];
}

int main(void){
  char s1[100],s2[100];
  // scanf("%99[^\n]", s1); 
  fgets(s1, sizeof(s1), stdin); 
  fgets(s2, sizeof(s2), stdin); 
  int D = solveMED(s1, s2);
  printf("%d\n", D);
  return 0;
}