#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target;
    cin >> target; 
    int l = 0; int r = n-1;
    int ans = -1;
    while(l <= r) {
        int m = (l+r)/2;
        if(a[m] == target) {
            ans = m;
            r = m-1;
        }
        else if(a[m] < target) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    if(ans != -1) cout << ans;
    else cout << l;
    
    return 0;
}