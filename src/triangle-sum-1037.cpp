#include <bits/stdc++.h>
using namespace std;

const int MAXN = 111;
int reward[MAXN][MAXN];
long long f[MAXN][MAXN];
int n;

void read(int n){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            scanf("%d", &reward[i][j]);
        }
    }
}

long long solve(int n){
    memset(f, 0, sizeof(f));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            f[i][j] = max(f[i-1][j-1], f[i-1][j]) + reward[i][j];
        }
    }
    long long ans = 0;
    for (int j=1; j<=n; j++){
        ans = max(ans, f[n][j]);
    }
    return ans;
    // return 1;
}

int main(){
    scanf("%d", &n);
    read(n);
    printf("%lld\n", solve(n));
}