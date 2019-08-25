# include<cstdio>
# include<algorithm>
using namespace std;

int N, M;
int days[111];

void solve(){
    if (N <= M){
        puts("100");
        return;
    }

    int ans = 0;
    for (int r=M+1;r<N;r++){
        ans = max(ans, days[r] - days[r - M -1] - 1);
    }
    ans = max(ans, days[M] - 1);
    ans = max(ans, 100 - days[N-M-1]);
    printf("%d\n", ans);
    return;
}

int main(){
    int _;scanf("%d", &_);
    while (_--){
        scanf("%d%d", &N, &M);
        for (int i=0; i<N; i++){
            scanf("%d", days+i);
        }
        sort(days, days+N);
        solve();
    }
    return 0;
}
