#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  int mx = a[n-1], r = 0;
  double mid = mx/2.0;
  int minDiff = INF;

  REP(i,n-1) {
    double diff = abs(mid - a[i]);
    if (diff < minDiff) {
      r = a[i];
      minDiff = diff;
    }
  }

  cout << mx << " " << r << endl;
  return 0;
}