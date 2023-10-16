#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
int n;
int a[MAXN];
vector<int> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    v.push_back(a[0]);
    for(int i = 1; i < n; i++) {
        if(v[v.size()-1] < a[i]) {
            v.push_back(a[i]);
            continue;
        }

        int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        v[idx] = a[i];
    }

    cout << v.size() << "\n";

    return 0;
}