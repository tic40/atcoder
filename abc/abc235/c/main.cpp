#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  map<int, vector<int>> mp;

  REP(i,n) cin >> a[i];
  REP(i,n) mp[a[i]].push_back(i);

  REP(i,q) {
    int x,k; cin >> x >> k;
    int ans = -1;
    if (k <= (int)mp[x].size()) ans = mp[x][k-1]+1;
    cout << ans << endl;
  }

  return 0;
}