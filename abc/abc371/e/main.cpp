#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector positions(200005,vector<int>());

  REP(i,n) {
    int a; cin >> a;
    positions[a].push_back(i);
  }
  // 番兵追加
  for(auto& v: positions) v.push_back(n);

  ll tot = (ll)n*(n+1)/2;
  ll ans = 0;
  for (auto& pos : positions) {
    ll tot_without_x = 0;
    int prev = -1;
    for(auto v: pos) {
      int start = prev + 1;
      int end = v - 1;
      int len = end - start + 1;
      tot_without_x += (ll)len*(len+1)/2;
      prev = v;
    }
    ans += tot - tot_without_x;
  }

  cout << ans << endl;
  return 0;
}