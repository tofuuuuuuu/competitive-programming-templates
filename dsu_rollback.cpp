#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 500000;
int p[MAXN];
int r[MAXN];
stack<pii> s;

pii makePair(int a, int b) {
    pii p; p.first = a; p.second = b; return p;
}
 
void init(int N) {
    for(int i = 1; i <= N; i++) {
        p[i] = i;
        r[i] = 0;
    }
}

int find(int v) {
    if(p[v] == v) return v;
    return find(p[v]);
}

void AddEdge(int U, int V) {
    int p1 = find(U); int p2 = find(V);
    
    if(p1 == p2) {
        s.push(makePair(0, 0));
        return;
    }

    if(r[p1] == r[p2]) {
        p[p2] = p1;
        r[p1]++;
        s.push(makePair(p1, p2));
    }
    else if(r[p1] > r[p2]){
        p[p2] = p1;
        s.push(makePair(p1, p2));
    }
    else {
        p[p1] = p2;
        s.push(makePair(p2, p1));
    }
}

void RemoveLastEdge() {
    pii lastEdge = s.top(); 
    s.pop();
    int p1 = lastEdge.first; int p2 = lastEdge.second;
    p[p2] = p2;
}

int GetSize(int U) {
    int p1 = find(U);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}