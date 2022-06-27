#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;

  // ランレングス圧縮
  vector<pair<char,int>> vs;
  vs.emplace_back(s[0], 1);
  for(int i = 1; i < n; i++) {
    if (s[i-1] == s[i]) vs.back().second++;
    else vs.emplace_back(s[i], 1);
  }

  // しゃくとり
  int ans = 0, sum = 0, l = 0, zero = 0;
  REP(i,(int)vs.size()) {
    if (vs[i].first == '0') zero++;
    sum += vs[i].second;

    while(k < zero) {
      if (vs[l].first == '0') zero--;
      sum -= vs[l].second;
      l++;
    }

    ans = max(ans,sum);
  }
  cout << ans << endl;

  return 0;
}
