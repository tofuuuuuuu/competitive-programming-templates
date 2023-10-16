#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll MOD = 10000000007;

ll quickPow(ll b, ll p) {
    ll ans = 1;
    ll cur = b;
    while(p) {
        if(p & 1) {
            ans *= cur;
            ans %= MOD;
        }  
        p >>= 1;
        cur *= cur;
        cur %= MOD;
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}