#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; string s; cin >> n >> s;

  vector<P> vs;
  REP(i,n) {
    if (vs.size() && vs.back().first == s[i]) vs.back().second++;
    else vs.emplace_back(s[i],1);
  }

  int ans = 1;
  REP(i,(int)vs.size()) if (i > 0 && i < (int)vs.size()-1 && vs[i].first == '/' && vs[i].second == 1) {
    if (vs[i-1].first == '1' && vs[i+1].first == '2') {
      ans = max(ans, min(vs[i-1].second, vs[i+1].second) * 2 + 1);
    }
  }

  cout << ans << endl;
  return 0;
}