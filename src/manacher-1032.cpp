#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.5e6;
char s[MAXN];
char s_aug[MAXN];
int inv_len[MAXN];
int solve(char *s)
{
    s_aug[0] = '$';
    memset(inv_len, 0, sizeof(inv_len));
    inv_len[0] = 1;
    int s_aug_len, s_len;
    s_len = strlen(s);
    s_aug_len = 0;
    for (int i=0; i<s_len; i++){
        s_aug[++s_aug_len] = '#';
        s_aug[++s_aug_len] = s[i];
    }
    s_aug[++s_aug_len] = '#';
    // printf("len %d\n", s_aug_len);
    // puts(s_aug);
    int mid = 1, ans = 0;
    for (int now=1; now<=s_aug_len; now++){
        inv_len[now] = max(1, min(inv_len[2*mid - now], inv_len[mid] - 2 * (now - mid)));
        int i = now - inv_len[now] / 2;// inverse upside down
        int j = now + inv_len[now] / 2;// inverse upsice down
        // printf("now %d,inv_len[now] %d, i %d, j %d\n", now, inv_len[now], i, j);
        while (s_aug[i-1] == s_aug[j+1]){
            i--, j++;
            inv_len[now] += 2;
        }
        // printf("i %d j %d\n", i, j);
        if (mid + inv_len[mid] / 2 <= now + inv_len[now] / 2){
            mid = now;
        }
        // printf("%d %d\n", now, inv_len[now]);
        ans = max(ans, inv_len[now] / 2);
    }
    return ans;
}
int main()
{
    int _;scanf("%d", &_);
    while (_--){
        scanf("%s", s);
        printf("%d\n", solve(s));
    }
}