#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int N = 1005;
int dp[N][N];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int dCost, iCost, rCost;
    cin >> dCost >> iCost >> rCost;
    string a; string b;
    cin >> a >> b;
    int n = a.length(); int m = b.length();

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dCost*i;
    }
    for(int j = 1; j <= m; j++) {
        dp[0][j] = iCost*j;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                //insertion, replace, deletion
                dp[i][j] = min(dp[i][j-1] + iCost, min(dp[i-1][j-1] + rCost, dp[i-1][j] + dCost));
            }
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}