#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  if (k == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  vector<int> b = a;
  sort(b.begin(),b.end());

  vector<vector<int>> g(k);
  REP(i,n) g[i%k].push_back(a[i]);
  REP(i,k) sort(g[i].begin(),g[i].end());
  REP(i,n) {
    if (i/k <= (int)g[i%k].size()-1) a[i] = g[i%k][i/k];
  }

  bool ok = a == b;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}