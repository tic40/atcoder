#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  auto solve = []() -> bool {
    int n; cin >> n;
    vector<int> a(n);
    REP(i,n) cin >> a[i];

    sort(a.begin(),a.end(),[&](int x, int y){ return abs(x) < abs(y); });

    bool ok = true;
    REP(i,n-2) {
      // a[i] / a[i+1] = a[i+1] / a[i+2]
      // a[i] * a[i+2] = a[i+1] * a[i+1]
      if ((ll)a[i]*a[i+2] != (ll)a[i+1]*a[i+1]) ok = false;
    }
    if (ok) return true;

    if (abs(a[0]) == abs(a.back())) {
      int pos = 0, neg = 0;
      REP(i,n) a[i] < 0 ? neg++ : pos++;
      if (abs(neg-pos) <= 1) return true;
    }
    return false;
  };

  int t; cin >> t;
  REP(_,t) cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}