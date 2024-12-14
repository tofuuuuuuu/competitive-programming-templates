#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
int n, sz, k;

struct sliding_median {
    int x[MAXN];
    int n, sz;
    ll sumLow, sumHigh, ans, curAns, m;
    multiset<int> sLow;
    multiset<int> sHigh;
    vector<int> temp;

    void init() {
        sumLow = 0; sumHigh = 0; ans = (ll)1e25; 
        sort(temp.begin(), temp.end());

        for(int i = 1; i <= sz/2; i++) {
            sLow.insert(temp[i-1]);
            sumLow += temp[i-1];
        }
        for(int i = sz/2 + 1; i <= sz; i++) {
            sHigh.insert(temp[i-1]);
            sumHigh += temp[i-1];
        }
    }

    void get_median() {
        m = *sHigh.begin();
        curAns = sumHigh - m * (sHigh.size());
        curAns += m * (sLow.size()) - sumLow; 
        cout << curAns << " ";
    }

    void remove(int sz) {
        if(sLow.size() > 0 && sLow.find(sz) != sLow.end()) {
            sLow.erase(sLow.find(sz));
            sumLow -= sz;
        }
        else {
            sHigh.erase(sHigh.find(sz));
            sumHigh -= sz;
        }
    }

    void insert(int sz) {
        if(sLow.size() > 0 && sz < *sLow.rbegin()) {
            sLow.insert(sz);
            sumLow += sz;
        }
        else {
            sHigh.insert(sz);
            sumHigh += sz;
        }
    }

    void rebalance() {
        if(sLow.size() > sz/2) {
            int a = *sLow.rbegin();
            sLow.erase(sLow.find(a));
            sHigh.insert(a);
            sumLow -= a;
            sumHigh += a;
        }
        if(sHigh.size() > (sz+1)/2) {
            int a = *sHigh.begin();
            sHigh.erase(sHigh.find(a));
            sLow.insert(a);
            sumLow += a;
            sumHigh -= a;
        }
    }
} md;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    md.init(); //read in sz amt of elements first

    md.remove(k); //peform in this order
    md.insert(k);
    md.rebalance();

    md.get_median(); //gets median

    return 0;
}