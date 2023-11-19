#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<char,int>;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  // ランレングス圧縮
  vector<P> m;
  for(char c: s) {
    if (m.size() > 0 && m.back().first == c) {
      m.back().second++;
    } else {
      m.emplace_back(c,1);
    }
  }

  vector<int> a(26);
  for(auto [c,v]: m) a[c-'a'] = max(a[c-'a'],v);
  int ans = accumulate(a.begin(),a.end(),0);
  cout << ans << endl;

  return 0;
}