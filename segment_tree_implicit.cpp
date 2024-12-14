#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 10000000;

struct Node{
    int l = 0; int r = 0; ll valSum = 0;
};

struct {
    Node seg[MAXN];
    int nextFree = 2;

    void pushup(int cur) {
        seg[cur].valSum = seg[seg[cur].l].valSum + seg[seg[cur].r].valSum;
    }

    void update(int cur, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            seg[cur].valSum = val;
            return;
        }
        
        ll m = (l+r)/2;
        if(idx <= m) {
            if(seg[cur].l == 0){
                seg[cur].l = nextFree;
                nextFree++;
            }
            seg[seg[cur].l].valSum = val;
            update(seg[cur].l, l, m, idx, val);
        }
        else {
            if(seg[cur].r == 0){
                seg[cur].r = nextFree;
                nextFree++;
            }
            seg[seg[cur].r].valSum = val;
            update(seg[cur].r, m+1, r, idx, val);
        }
        pushup(cur);
    }

    ll querySum(int cur, ll l, ll r, ll ql, ll qr) {
        if(ql <= l && r <= qr) return seg[cur].valSum;
        if(r < ql || qr < l) return 0;

        ll m = (l+r)/2;
        ll sumL = 0; ll sumR = 0;
        if(seg[cur].l != 0) sumL = querySum(seg[cur].l, l, m, ql, qr);
        if(seg[cur].r != 0) sumR = querySum(seg[cur].r, m+1, r, ql, qr);
        return sumL + sumR;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);


    
    return 0;
}