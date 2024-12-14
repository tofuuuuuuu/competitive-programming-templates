#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 1000005;
const ll BFN = (ll)1e19;
//const int BFN = (int)1e9;
int t, n;

struct Trie {
    int trie[MAXN][26];
    int t, nxtFree;
    string s;

    void init() {
        nxtFree = 1;
        for(int i = 0; i < MAXN; i++) {
            for(int j = 0; j < 26; j++) {
                trie[i][j] = -1;
            }
        }
    }

    void add(int cur, int charPos) {
        if(charPos == s.size()) {
            return;
        }
        if(trie[cur][s[charPos] - 'a'] != -1) {
            cur = trie[cur][s[charPos] - 'a'];
            add(cur, charPos+1);
            return;
        }
        
        trie[cur][s[charPos] - 'a'] = nxtFree; 
        cur = nxtFree;
        nxtFree++;
        return add(cur, charPos+1);
    }

    bool find(int cur, int charPos) { //is in trie (true = in)
        if(charPos == s.size()) {
            return true;
        }
        if(trie[cur][s[charPos] - 'a'] != -1) {
            cur = trie[cur][s[charPos] - 'a'];
            return find(cur, charPos+1);
        }
        return false;
    }

    int prefix(int cur, int charPos, int ans) { //shortest unique prefix
        if(charPos == s.size()) {
            if(ans == 0) ans = charPos;
            return ans;
        }
        if(trie[cur][s[charPos] - 'a'] != -1) {
            cur = trie[cur][s[charPos] - 'a'];
            return prefix(cur, charPos+1, ans);
        }
        
        return charPos + 1;
    }
} tr;

void sol() {
    tr.init();

    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> tr.s;
        if(tr.find(0, 0)) sum += tr.s.size();
        else sum += tr.prefix(0, 0, 0);
        tr.add(0, 0);
    }
    cout << "Case #" << t << ": " << sum << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}
