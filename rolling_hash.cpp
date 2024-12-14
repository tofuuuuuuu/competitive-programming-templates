#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int MAXL = 100000;
ll hash1[MAXL];
ll hash2[MAXL];
ll pow1[MAXL];
ll pow2[MAXL];
const ll base1 = 137;
const ll base2 = 131; 
const ll mod1 = 1000000007;
const ll mod2 = 1000000009;

ll getHash(ll *hash, ll *pow, int l , int r, ll mod) {
    if(l == 0) return hash[r];
    ll a = (hash[r] - (hash[l-1] * pow[r - l + 1]) % mod) % mod;
    if(a < 0) a += mod;
    return a;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    pow1[0] = 1; 
    pow2[0] = 1; 
    for(int i = 1; i < MAXL; i++) {
        pow1[i] = (pow1[i-1] * base1) % mod1;
        pow2[i] = (pow2[i-1] * base2) % mod2;
    }

    string n, h; cin >> n >> h;
    int nL = n.length(); int hL = h.length();

    hash1[0] = h[0]; hash2[0] = h[0];
    for(int i = 1; i < hL; i++) {
        hash1[i] = ((hash1[i-1] * base1) % mod1 + h[i]) % mod1;
    }
    for(int i = 1; i < hL; i++) {
        hash2[i] = ((hash2[i-1] * base2) % mod2 + h[i]) % mod2;
    }

    int l, r;
    ll hashVal1 = getHash(hash1, pow1, l, r, mod1);
    ll hashVal2 = getHash(hash2, pow2, l, r, mod2);

    //equality when hashVal1 == hashVal1 && hashVal2 == hashVal2
    //0 indexed

    return 0;
}