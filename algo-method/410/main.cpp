#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  auto f = [&](int x, int y) {
    int res = 0;
    // white
    for (int i = 0; i < x; i++) REP(j,m) if (s[i][j] != 'W') res++;
    // blue
    for (int i = x; i <= y; i++) REP(j,m) if (s[i][j] != 'B') res++;
    // red
    for (int i = y+1; i < n; i++) REP(j,m) if (s[i][j] != 'R') res++;

    return res;
  };

  int ans = INF;
  for(int i = 1; i < n-1; i++) {
    for (int j = i; j < n-1; j++) {
      ans = min(ans, f(i,j));
    }
  }

  cout << ans << endl;
  return 0;
}