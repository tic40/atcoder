#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  if (k == 1) { cout << "Yes" << endl; return 0; }

  vector<vector<int>> g(n);
  REP(i,n) g[i%k].push_back(a[i]);
  REP(i,n) sort(g[i].begin(),g[i].end());

  REP(i,n) a[i] = g[i%k][i/k];
  vector<int> b = a;
  sort(b.begin(),b.end());
  cout << (a == b ? "Yes" : "No") << endl;
  return 0;
}
