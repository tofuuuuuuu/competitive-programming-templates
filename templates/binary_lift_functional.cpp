#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 30;
const ll BFN = (ll)1e19;
//const int BFN = (int)1e9;
int nxt[MAXN];
int newNxt[MAXN];
int tmp[MAXN];
ll n;
char c;
string s;

int getVal(char ch) {
    if(ch == '_') return 27;
    return ch - 'A' + 1;
}

void bigLift() {
    while(n > 0) {
        if(n % 2 == 1) {
            for(int i = 1; i <= 27; i++) {
                nxt[i] = newNxt[nxt[i]];
            }
        }

        n /= 2;
        for(int i = 1; i <= 27; i++) {
            tmp[i] = newNxt[i];
        }
        for(int i = 1; i <= 27; i++) {
            newNxt[i] = tmp[tmp[i]];
        }
    }
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 27; i++) {
        cin >> c;
        c = getVal(c);

        nxt[i] = i;
        newNxt[i] = c;
    } 
    cin >> n;

    bigLift();
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        c = getVal(s[i]);
        c = nxt[c];
        if(c == 27) c = '_';
        else c = c + 'A' - 1;

        cout << (char)c;
    }
    cout << "\n";

    return 0;
}