#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int f(string& s, int idx) { return s.substr(idx,3) == "ABC"; }

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  int ans = 0;
  REP(i,n-2) ans += f(s,i);

  REP(_,q) {
    int x; char c; cin >> x >> c; x--;
    for(int i = max(0,x-2); i <= x; i++) ans -= f(s,i);
    s[x] = c;
    for(int i = max(0,x-2); i <= x; i++) ans += f(s,i);

    cout << ans << endl;
  }
  return 0;
}