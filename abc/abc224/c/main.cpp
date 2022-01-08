#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int n;
vector<pair<int,int>> p;

void solve() {
  ll ans = 0;
  REP(i,n) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        auto a = p[i];
        auto b = p[j];
        auto c = p[k];

        // a,b a,c の傾きを調べて同じだったら同一直線上
        ll d1 = b.second - a.second;
        ll d2 = c.second - a.second;
        d1 *= c.first - a.first;
        d2 *= b.first - a.first;

        // a-bの傾きとa-cの傾きを比較
        if (d1 == d2) continue;
        ans++;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> n;
  p.resize(n);
  REP(i,n) {
    int x,y; cin >> x >> y;
    p[i] = {x,y};
  }

  solve();
  return 0;
}