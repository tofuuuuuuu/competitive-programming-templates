#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
int nextN[MAXN];
int inDeg[MAXN];
int removed[MAXN];
int maxLength[MAXN];

void findCycles(int n) {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        removed[i] = 0;
        if(inDeg[i] == 0) {
            q.push(i);
            removed[i] = 1;
        }
    }
    
    while(!q.empty()) {
        int v = q.front(); q.pop();
        inDeg[nextN[v]]--;
        if(inDeg[nextN[v]] == 0) {
            q.push(nextN[v]);
            removed[nextN[v]] = 1;
        }
    }
}

void processCycle(int v) {
    vector<int> cycleNodes;
    int curNode = v;
    while(!removed[curNode]) {
        removed[curNode] = 1;
        cycleNodes.push_back(curNode);
        curNode = nextN[curNode];
    }

    for(int i : cycleNodes) {
        maxLength[i] = cycleNodes.size();
    }
}

void processNode(int v) {
    if(maxLength[v] != 0) return;

    processNode(nextN[v]);
    maxLength[v] = maxLength[nextN[v]] + 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(maxLength, 0, sizeof(maxLength));

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        inDeg[a]++;
        nextN[i] = a;
    }

    findCycles(n);

    for(int i = 0; i < n; i++) {
        if(!removed[i]) processCycle(i);
    }
    for(int i = 0; i < n; i++) {
        if(maxLength[i] == 0) {
            processNode(i);
        }
    }

    return 0;
}