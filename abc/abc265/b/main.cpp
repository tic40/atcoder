#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m;
  ll t;
  cin >> n >> m >> t;
  vector<int> a(n-1);
  REP(i,n-1) cin >> a[i];

  vector<int> b(n);
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--;
    b[x] = y;
  }

  bool ok = true;
  REP(i,n-1) {
    t += b[i];
    t -= a[i];
    if (t <= 0) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}