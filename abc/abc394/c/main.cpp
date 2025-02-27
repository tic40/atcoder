#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<pair<char,int>> pa;
  for(auto c: s) {
    if (pa.size() && pa.back().first == c) pa.back().second++;
    else pa.emplace_back(c,1);
  }
  int n = pa.size();
  pa.emplace_back('_',0);
  REP(i,n) {
    auto [c,cnt] = pa[i];
    if (cnt == 0) continue;

    if (c == 'W' && pa[i+1].first == 'A') {
      cout << 'A';
      REP(j,cnt) cout << 'C';
      pa[i+1].second--;
    } else {
      REP(j,cnt) cout << c;
    }
  }

  return 0;
}
