#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector<int> b(n);
  iota(b.begin(),b.end(),0);
  bool ans = false;
  do {
    bool ok = true;
    REP(i,n-1) {
      int cnt = 0;
      REP(j,m) if (s[b[i]][j] != s[b[i+1]][j]) cnt++;
      if (cnt != 1) ok = false;
    }
    ans = ans || ok;
  } while (next_permutation(b.begin(), b.end()));

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}