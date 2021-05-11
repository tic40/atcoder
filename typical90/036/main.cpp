#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int N,Q;
vector<ll> x,y;
vector<int> q;

void solve() {
  ll minX = 1LL << 60;
  ll maxX = -(1LL << 60);
  ll minY = 1LL << 60;
  ll maxY = -(1LL << 60);

  // 45度回転させる
  REP(i,N) {
    ll p1 = x[i] + y[i];
    ll p2 = y[i] - x[i];
    x[i] = p1;
    y[i] = p2;
    minX = min(minX,x[i]);
    maxX = max(maxX,x[i]);
    minY = min(minY,y[i]);
    maxY = max(maxY,y[i]);
  }

  REP(i,Q) {
    cout << max({
      abs(x[q[i]] - minX),
      abs(x[q[i]] - maxX),
      abs(y[q[i]] - minY),
      abs(y[q[i]] - maxY)
    }) << endl;
  }
 return;

}

int main() {
  cin >> N >> Q;
  x.resize(N);
  y.resize(N);
  q.resize(Q);
  REP(i,N) cin >> x[i] >> y[i];
  REP(i,Q) {
    cin >> q[i];
    q[i]--;
  }

  solve();
  return 0;
}