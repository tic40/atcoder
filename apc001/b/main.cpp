#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a,b;

void solve() {
  ll add = 0;

  REP(i,n) {
    if (a[i] == b[i]) continue;
    int d = abs(a[i]-b[i]);

    if (a[i] < b[i]) add += d%2==0 ? d/2 : (d-1)/2;
    else add -= d;
  }

  string ans = 0 <= add ? "Yes" : "No";
  cout << ans << endl;

  return;
}

int main() {
  cin >> n;
  a.resize(n); b.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  solve();
  return 0;
}