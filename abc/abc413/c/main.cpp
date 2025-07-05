#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int q; cin >> q;
  vector<P> pa;
  int cursor = 0;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      ll c,x; cin >> c >> x;
      pa.emplace_back(x,c);
    }
    if (t == 2) {
      int k; cin >> k;
      ll tot = 0;
      while(k > 0) {
        auto [x,c] = pa[cursor];
        int cnt = min(k,c);
        tot += (ll)cnt * x;
        pa[cursor].second -= cnt;
        k -= cnt;
        if (pa[cursor].second == 0) cursor++;
      }
      cout << tot << endl;
    }
  }
  return 0;
}