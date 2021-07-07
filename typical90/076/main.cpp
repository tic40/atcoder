#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a;

void solve() {
  ll sum = 0;
  REP(i,n) sum += a[i];
  if (sum % 10 > 0) {
    cout << "No" << endl;
    return;
  }

  ll p = sum / 10;
  sum = 0;
  int r = 0;

  REP(l,n*2) {
    while (r < n*2) {
      if (sum == p) {
        cout << "Yes" << endl;
        return;
      }
      if (p < sum) break;

      sum += a[r%n];
      r++;
    }
    if (r == l) r++;
    sum -= a[l%n];
  }

  cout << "No" << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}