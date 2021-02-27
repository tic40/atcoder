#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> c,s,f;

void solve() {
  REP(i,n) {

    int now = 0;
    for (int j = i; j < n-1; j++) {
      if (now <= s[j]) {
        now = s[j];
      } else {
        if (now % f[j]) now += f[j] - now%f[j];
      }
      now += c[j];
    }
    cout << now << endl;
  }
  return;
}

int main() {
  cin >> n;
  c.resize(n-1); s.resize(n-1); f.resize(n-1);
  REP(i,n-1) cin >> c[i] >> s[i] >> f[i];

  solve();
  return 0;
}