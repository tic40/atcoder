#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,k; string s;
  cin >> n >> k >> s;

  // ランレングス圧縮
  vector<pair<char,int>> vs;
  vs.push_back({ s[0], 1 });
  for(int i = 1; i < n; i++) {
    if (s[i] == s[i-1]) vs.back().second++;
    else vs.push_back({ s[i], 1 });
  }

  int zero = 0;
  int now = 0;
  int ans = 0;
  int l = 0;
  REP(i,(int)vs.size()) {
    if (vs[i].first == '0') zero++;
    now += vs[i].second;

    while(k < zero) {
      if (vs[l].first == '0') zero--;
      now -= vs[l].second;
      l++;
    }
    ans = max(ans,now);
  }

  cout << ans << endl;
  return 0;
}