#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    ll value[n+1];
    ll weight[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    ll dp[w+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = w; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[w] << "\n";

    return 0;
}