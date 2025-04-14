#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector menus(n,vector<int>());
  vector<int> cnt(m);
  REP(i,m) {
    int k; cin >> k;
    cnt[i] = k;
    REP(j,k) {
      int a; cin >> a; a--;
      menus[a].push_back(i);
    }
  }

  int ans = 0;
  REP(i,n) {
    int b; cin >> b; b--;
    for(auto v: menus[b]) {
      cnt[v]--;
      if (cnt[v] == 0) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}