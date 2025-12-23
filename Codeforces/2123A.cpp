#include<cstdio>

void solve(){
    int n; scanf("%d",&n);
    printf("%s\n", (n % 4 == 0) ? "Bob" : "Alice");
}
int main(void){
    int t; scanf("%d",&t);
    while(t--) solve();
}