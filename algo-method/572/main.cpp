#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  REP(i,h) {
    vector<int> ans(w);
    REP(j,w) {
      if (s[i][j] == 'c') {
        ans[j] = 0;
        continue;
      }
      ans[j] = (0 < j && ans[j-1] != -1) ? ans[j-1]+1 : -1;
    }
    REP(i,w) cout << ans[i] << " ";
    cout << endl;
  }


  return 0;
}