#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  REP(i,n-1) {
    int d = a[i+1] - a[i];
    if (d == 0) cout << "stay" << endl;
    else if (0 < d) cout << "up " << d << endl;
    else cout << "down " << -d << endl;
  }
  return 0;
}