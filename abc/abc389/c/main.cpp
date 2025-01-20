#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int q; cin >> q;
  vector<pair<ll,int>> vs;
  ll now = 0;
  int head = 0;
  ll diff = 0;
  while(q--) {
    int t; cin >> t;
    if (t == 1) {
      int l; cin >> l;
      vs.emplace_back(now,l);
      now += l;
    }
    if (t == 2) {
      diff += vs[head].second;
      head++;
    }
    if (t == 3) {
      int k; cin >> k; k--;
      ll ans = vs[k+head].first - diff;
      cout << ans << endl;
    }
  }
  return 0;
}