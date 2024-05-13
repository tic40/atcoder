#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const vector<int> coins = { 500, 100, 50, 10, 5, 1 };

int main() {
  vector<int> cnt(6);
  REP(i,6) cin >> cnt[i];
  int n; cin >> n;

  reverse(cnt.begin(),cnt.end());
  bool ok = true;
  REP(i,n) {
    int x; cin >> x;
    REP(j,6) {
      int r = min(cnt[j], x / coins[j]);
      cnt[j] -= r;
      x -= coins[j] * r;
    }
    if (x != 0) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}