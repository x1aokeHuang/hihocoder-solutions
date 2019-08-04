#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.5e5;
int n, C;
int f[MAXN], v[MAXN], c[MAXN];

int main(){
    scanf("%d%d", &n, &C);
    for (int i=1; i<=n; i++){
        scanf("%d%d", &c[i], &v[i]);
    }
    for (int i=1; i<=n; i++){
        for (int j=c[i]; j<=C; j++){
            f[j] = max(f[j], f[j-c[i]] +v[i]);
        }
    }
    printf("%d\n", f[C]);
}