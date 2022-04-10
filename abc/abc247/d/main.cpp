#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int q; cin >> q;
  deque<pair<int,int>> dq;

  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,c; cin >> x >> c;
      dq.push_back({x,c});
    } else {
      int c; cin >> c;

      ll sum = 0;
      while(0 < c) {
        auto [nx,nc] = dq.front(); dq.pop_front();
        int k = min(c,nc);
        sum += (ll)nx*k;
        if (k < nc) dq.push_front({nx,nc-k});
        c -= k;
      }
      cout << sum << endl;
    }
  }
  return 0;
}