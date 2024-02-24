#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; string s;
  cin >> n >> s >> q;
  vector<char> c(26);
  REP(i,26) c[i] = char('a' + i);
  REP(_,q) {
    char a,b; cin >> a >> b;
    REP(i,26) if (c[i] == a) c[i] = b;
  }
  for(auto v: s) cout << c[v-'a'];
  return 0;
}