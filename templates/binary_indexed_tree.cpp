#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000000;
struct {
    int BIT[MAXN];

    int lowbit(int n) {return n&(-n);}

    void update(int idx, int val) {
        for(int i = idx; i < MAXN; i+=lowbit(i)) {
            BIT[i] += val;
        }
    }

    ll query(int idx) {
        ll ans = 0;
        for(int i = idx; i > 0; i-=lowbit(i)) {
            ans += BIT[i];
        }
        return ans;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}