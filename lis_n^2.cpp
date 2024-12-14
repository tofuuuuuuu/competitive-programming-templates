#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int lis[n];
    memset(lis, 0, sizeof(lis));
    for(int i = 0; i < n; i++) {
        lis[i] = 1;
        for(int j = i-1; j >= 0; j--) {
            if(a[i] > a[j]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, lis[i]);
    }
    cout << ans << "\n";

    return 0;
}