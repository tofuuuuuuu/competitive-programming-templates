#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int MAXN = 100005;
int nxt[MAXN];
string t, p;

int kmp(string text, string pattern) {
    int n = text.size(), m = pattern.size(), cnt = 0;

    nxt[0] = -1;
    int j = - 1;
    for(int i = 1; i < n; i++) {
        while(j != -1 && text[i] != pattern[j+1]) j = nxt[j];

        if(text[i] == pattern[j+1]) j++;
        nxt[i] = j;

        if(j == m-1) {
            cnt++;
            j = -1;
        }
    } 
    return cnt;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> p;
    cout << kmp(t, p) <<"\n";

    return 0;
}