#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; string s;
  cin >> n >> s;
  vector<vector<int>> m(10);
  REP(i,n) m[s[i]-'0'].push_back(i);

  auto possible = [&](int now) {
    int p = 0;
    REP(_,3) {
      int x = now%10;
      now /= 10;

      auto it = lower_bound(m[x].begin(), m[x].end(), p);
      if (it == m[x].end() || *it < p) return false;
      p = *it + 1;
    }
    return true;
  };

  int ans = 0;
  REP(i,1000) if (possible(i)) ans++;

  cout << ans << endl;
  return 0;
}