#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  unordered_set<int> X,Y,S,D;
  REP(_,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    X.insert(a);
    Y.insert(b);
    S.insert(a+b);
    D.insert(a-b);
  }

  ll ans = (ll)n*n; // total
  // x 直線分
  ans -= n * X.size();
  // y 直線分
  ans -= n * Y.size();
  for(int s: S) ans -= n - abs(s-(n-1));
  for(int d: D) ans -= n - abs(d);

  map<P,int> cnt;
  auto add = [&](int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    cnt[P(x,y)]++;
  };

  for(int x: X) for(int y: Y) add(x,y);
  for(int x: X) for(int s: S) add(x,s-x);
  for(int x: X) for(int d: D) add(x,x-d);
  for(int y: Y) for(int s: S) add(s-y,y);
  for(int y: Y) for(int d: D) add(y+d,y);
  for(int s: S) for(int d: D) {
    if ((s+d)%2) continue;
    add((s+d)/2,(s-d)/2);
  }

  for(auto [_,num]: cnt) {
    if (num == 1) ans += 1;
    if (num == 3) ans += 2;
    if (num == 6) ans += 3;
  }
  cout << ans << endl;
  return 0;
}