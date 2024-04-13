#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const unordered_set atcset = { 'a','t','c','o','d','e','r' };
int main() {
  string s,t; cin >> s >> t;
  auto f = [&](string s) {
    vector<int> cnt(27);
    for(auto c: s) cnt[ c == '@' ? 26 : c-'a']++;
    return cnt;
  };

  vector<vector<int>> cnt = {f(s),f(t)};
  bool ok = true;
  REP(i,26) {
    int d = cnt[0][i] - cnt[1][i];
    if (d == 0) continue;

    if (atcset.find(char('a'+i)) == atcset.end()) ok = false;
    else cnt[d >= 0].back() -= abs(d);
  }
  ok = ok && (cnt[0].back() == cnt[1].back() && cnt[0].back() >= 0);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}