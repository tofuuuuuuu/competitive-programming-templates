#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
struct Segtree{
    ll a[MAXN];
    ll seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = (seg[2*cur] + seg[2*cur+1]);
    }

    void construct(int cur, int l, int r) {
        if(l == r) {
            seg[cur] = a[l];
            return;
        }

        int m = (l+r)/2;
        construct(cur*2, l, m);
        construct(cur*2 + 1, m+1, r);
        pushup(cur);
    } 

    void update(int cur, int l, int r, int idx, int val) {
        if(l == r) {
            seg[cur] = val;
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) return 0;
        int m = (l+r)/2;
        return (query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr));
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}