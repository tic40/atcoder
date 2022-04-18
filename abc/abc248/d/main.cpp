#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<vector<int>> g(n+1);
  REP(i,n) g[a[i]].push_back(i);

  int q; cin >> q;
  REP(i,q) {
    int l,r,x;
    cin >> l >> r >> x;
    l--; r--;

    vector<int>& now = g[x];
    auto itl = lower_bound(now.begin(), now.end(), l);
    auto itr = upper_bound(now.begin(), now.end(), r) - 1;
    cout << itr - itl + 1 << endl;
  }

  return 0;
}