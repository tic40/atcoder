#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int MOD = 998244353;

int n,m;
int a[300][300];
vector<int> s(300);

void solve() {
  int pos = 0;
  REP(j,m) {
    bool found = false;
    for(int i = pos; i < n; i++) {
      if (a[i][j]) {
        found = true;
        swap(a[pos],a[i]);
        break;
      }
    }

    if (found) {
      for(int i = pos+1; i < n; i++) {
        if (a[i][j]) {
          REP(k,m) {
            a[i][k] ^= a[pos][k];
          }
        }
      }
      if (s[j]) {
        REP(k,m) {
          s[k] ^= a[pos][k];
        }
      }
      pos++;
    }
  }

  REP(i,m) {
    if (s[i]) { cout << 0 << endl; return; }
  }

  ll ans = 1;
  for(int i = pos; i < n; i++) ans = ans * 2 % MOD;
  cout << ans << endl;

  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) {
    int t; cin >> t;
    REP(j,t) {
      int x; cin >> x;
      x--;
      a[i][x] = true;
    }
  }
  REP(i,m) cin >> s[i];

  solve();
  return 0;
}