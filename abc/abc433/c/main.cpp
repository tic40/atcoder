#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<P> vs;
  REP(i,n) {
    if (vs.size() && vs.back().first == s[i]-'0') vs.back().second++;
    else vs.emplace_back(s[i]-'0', 1);
  }
  ll ans = 0;
  REP(i, (int)vs.size()-1) {
    auto v1 = vs[i];
    auto v2 = vs[i+1];
    if (v1.first+1 != v2.first) continue; 
    ans += min(v1.second,v2.second);
  }
  cout << ans << endl;
  return 0;
}