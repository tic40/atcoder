#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector xs(2,vector<int>());
  vector ys(2,vector<int>());
  REP(i,n) {
    int x,y; cin >> x >> y;
    // { x,y } 座標を 45 度回転する
    int nx = x+y, ny = x-y;
    xs[nx%2].push_back(nx);
    ys[nx%2].push_back(ny);
  }

  auto f = [&](vector<int>& xs) {
    int n = xs.size();
    sort(xs.begin(),xs.end());
    ll res = 0;
    REP(i,n) {
      ll co = i - (n-i-1);
      res += co * xs[i];
    }
    return res/2;
  };

  ll ans = 0;
  REP(i,2) ans += f(xs[i]) + f(ys[i]);
  cout << ans << endl;
  return 0;
}