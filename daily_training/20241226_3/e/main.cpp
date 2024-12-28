#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector g(n,vector<int>());
  REP(i,n) g[i%k].push_back(a[i]);
  for(auto& v: g) sort(v.begin(),v.end());

  int prev = -1;
  bool ok = true;
  REP(i,n) {
    int now = g[i%k][i/k];
    if (prev > now) { ok = false; break; }
    prev = now;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}