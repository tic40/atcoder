#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(101);
  REP(i,n) {
    int x; cin >> x;
    a[x]++;
  }

  auto f = [](int x, int y) {
    ll x1 = 1, x2 = 1;
    REP(i,y) { x1 *= x-i; x2 *= y-i; }
    return x1/x2;
  };

  ll ans = 0;
  REP(i,101) {
    if (a[i] >= 3) ans += f(a[i],3);
  }
  cout << ans << endl;
  return 0;
}