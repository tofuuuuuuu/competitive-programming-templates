#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll MOD = 1000000007;

ll modInv(ll a) {
    ll p = MOD - 2;
    ll ans = 1;
    ll cur = a;
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