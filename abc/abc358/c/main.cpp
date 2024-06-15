#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 1e9;
  REP(bit,1<<n) {
    vector<int> now(m);
    int pcnt = 0;
    REP(i,n) if (bit >> i & 1) {
      pcnt++;
      REP(j,m) if (s[i][j] == 'o') now[j] = 1;
    }
    int s = accumulate(now.begin(),now.end(),0);
    if (s == m) ans = min(ans,pcnt);
  }
  cout << ans << endl;
  return 0;
}