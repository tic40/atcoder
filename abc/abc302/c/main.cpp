#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  auto f = [&](vector<int>& b) {
    REP(i,n-1) {
      auto now = s[b[i]], nx = s[b[i+1]];
      int cnt = 0;
      REP(j,m) if (now[j] != nx[j]) cnt++;
      if (cnt > 1) return false;
    }
    return true;
  };

  vector<int> b(n);
  iota(b.begin(),b.end(),0);
  bool ok = 0;
  do { ok |= f(b); } while (next_permutation(b.begin(),b.end()));
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}