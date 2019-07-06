#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
char s[MAXN],par[MAXN];//s src string, par parttren string.
int nxt[MAXN];
void get_next(){
    nxt[0] = -1;
    int p=1,q=-1;
    //p is s(par)'ptr,q is par's ptr 
    //q start with -1, because we don't want to match par[1],and nxt[1] should be 0;
    int len = strlen(par+1);// 1-base
    while (p <= len){
        while (par[p] != par[q+1] && q!=-1){//!!!key point
            q = nxt[q];
        }
        nxt[p] = q+1;
        p++,q++;
    }
}
void test_next(){
    int len = strlen(par+1);
    for (int i=0;i<=len;i++){
        printf(" %d",nxt[i]);
    }
    puts("");
}
int get_match(){
    int p=1, q=0;
    //p is s'ptr, q is par's ptr
    //q start with 0, because we try to match s[1],
    int ret = 0;
    int len = strlen(s+1), parlen = strlen(par+1);//1-base
    while (p <= len){
        while (s[p] != par[q+1] && q!=-1){//!!! key point
            q = nxt[q];
        }
        p++, q++;
        if (q == parlen){
            ret ++;
            q = nxt[q];// restart matching
        }
    }
    return ret;
}
int main()
{
    int n=1;
    scanf("%d",&n);
    while (n--){
        scanf("%s%s", par+1, s+1);//1-base
        get_next();
        // test_next();
        printf("%d\n",get_match());
    }
}