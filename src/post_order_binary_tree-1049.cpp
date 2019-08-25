#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char pre_ord[33], mid_ord[33];
int l[111], r[111], val[111];
int root=0;
int cnt=0;

int rebuild_tree(int pre_l, int pre_r, int mid_l, int mid_r){
    if (pre_l > pre_r){
        return 0;
    }

    int now_root = ++cnt;
    int now_mid_ind = 0, now_root_val = pre_ord[pre_l];
    for (int i=mid_l; i<=mid_r; i++){
        if (mid_ord[i] == now_root_val){
            now_mid_ind = i;
            break;
        }
    }
    int l_cnt = now_mid_ind - mid_l;
    
    val[now_root] = pre_ord[pre_l];
    l[now_root] = rebuild_tree(pre_l+1, pre_l+1+l_cnt-1, mid_l, now_mid_ind-1);
    r[now_root] = rebuild_tree(pre_l+l_cnt+1, pre_r, now_mid_ind+1, mid_r);
    return now_root;
}

void print_post_ord(int root_now){
    if (l[root_now]){
        print_post_ord(l[root_now]);
    }
    if (r[root_now]){
        print_post_ord(r[root_now]);
    }
    printf("%c", val[root_now]);
}

int main(){
    scanf("%s%s", pre_ord, mid_ord);

    int len=strlen(pre_ord);
    int pre_l=0, pre_r=len-1,
        mid_l=0, mid_r=len-1;

    root = rebuild_tree(pre_l, pre_r, mid_l, mid_r);
    print_post_ord(root);
}

