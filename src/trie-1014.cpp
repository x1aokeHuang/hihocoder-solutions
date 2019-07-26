#include<cstdio>
#include<cstring>
using namespace std;
#define _clr(a,b) memset(a,(b),sizeof(a))

const int MAXN = 1e6+10;//1e5 is insuffient for memory using
int trie[MAXN][50];


int cnt[MAXN];
int tot=1;
void Insert(char *s)
{
    int len = strlen(s);
    int now = 1;
    for (int i=0;i<len;i++){
        int ch = s[i] - 'a';
        if (trie[now][ch])
        {
            now = trie[now][ch]; 
            cnt[now]++;
        }
        else 
        {
            trie[now][ch] = ++tot;
            cnt[tot] ++;
            now = tot;
        }
    }
}
int query(char *s)
{
    int len = strlen(s);
    int now = 1;
    for (int i=0;i<len;i++)
    {
        int ch = s[i] - 'a';
        if (trie[now][ch])
        {
            now = trie[now][ch];
        }
        else return 0;
    }
    return cnt[now];
}
char s[20];
int main()
{
    int n;
    _clr(trie,0);
    _clr(cnt,0);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        Insert(s);
    }
    int q;scanf("%d",&q);
    while (q--){
        scanf("%s",s);
        printf("%d\n", query(s));
    }
}