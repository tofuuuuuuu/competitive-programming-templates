#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100000;
const int sqrtN = 320;
int a[MAXN];
int bucket[sqrtN];

void construct(int n) {
    for(int i = 0; i < sqrtN; i++) {
        bucket[i] = INT_MAX;
    }
    for(int i = 0; i < sqrtN; i++) {
        for(int j = i*sqrtN; j < (i+1)*sqrtN && j < n; j++) {
            bucket[i] = min(bucket[i], a[j]);
        }
    }
}

int getBucket(int idx) {
    return idx / sqrtN;
}

void update(int idx, int val) {
    int b = getBucket(idx);

    if(val < bucket[b]) {
        bucket[b] = val;
    }
    else if(bucket[b] == a[idx]) {
        a[idx] = val;
        int newMin = INT_MAX;
        for(int i = b*sqrtN; i < (b+1)*sqrtN; i++) {
            newMin = min(newMin, a[i]);
        }
        bucket[b] = newMin;
    }
    a[idx] = val;
}

int getMin (int l, int r) {
    int ans = INT_MAX;
    int lb = getBucket(l);
    int rb = getBucket(r);

    if(lb == rb) {
        for(int i = l; i <= r; i++) {
            ans = min(ans, a[i]);
        }
        return ans;
    }

    for(int i = lb + 1; i <= rb-1; i++) {
        ans = min(ans, bucket[i]);
    }
    for(int i = l; i < (lb+1)*sqrtN; i++) {
        ans = min(ans, a[i]);
    }
    for(int i = (rb)*sqrtN; i <= r; i++) {
        ans = min(ans, a[i]);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    construct(n);
    
    string qType;
    for(int i = 0; i < m; i++) {
        cin >> qType;
        if(qType[0] == 'M') {
            int idx, val; 
            cin >> idx >> val;
            update(idx, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << getMin(l, r) << "\n";
        }
    }

    return 0;
}