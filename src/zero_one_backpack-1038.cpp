#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 5e5;
int n, Col;
int col[MAXN], val[MAXN];
LL f[MAXN];

int main(){
    while (~scanf("%d%d", &n, &Col)){
    // scanf("%d%d", &n, &Col);
        for (int i=1;i<=n;i++){
            scanf("%d%d", &col[i], &val[i]);
        }
        memset(f, 0, sizeof(f));
        for (int i=1;i<=n;i++){
            for (int cur_col = Col ; cur_col >= col[i]; cur_col --){
                f[cur_col] = max(f[cur_col], f[cur_col - col[i]] + val[i]);
            }
        }
        printf("%lld", f[Col]);
        return 0;
    }
}