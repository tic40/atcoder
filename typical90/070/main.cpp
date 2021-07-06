#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> x,y;

void solve() {
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll ans = 0;
  int a = x[n/2], b = y[n/2];
  REP(i,n) {
    ans += abs(x[i]-a);
    ans += abs(y[i]-b);
  }
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  x.resize(n);
  y.resize(n);
  REP(i,n) {
    cin >> x[i] >> y[i];
  }

  solve();
  return 0;
}