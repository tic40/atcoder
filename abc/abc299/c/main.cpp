#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<char,int>;

int main() {
  int n; string s;
  cin >> n >> s;

  vector<P> pa;
  REP(i,n) {
    if (i > 0 && pa.back().first == s[i]) pa.back().second++;
    else pa.push_back({s[i],1});
  }

  int ans = 0, sz = pa.size();
  auto f = [&]() {
    REP(i,sz) {
      auto [c,cnt] = pa[i];
      if (c == '-' && i+1 < sz) ans = max(ans,pa[i+1].second);
    }
  };

  f();
  reverse(pa.begin(),pa.end());
  f();

  cout << (ans == 0 ? -1 : ans) << endl;
  return 0;
}