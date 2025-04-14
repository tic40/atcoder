#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  for(auto c: s) if (c == 'o') k--;
  if (k == 0) {
    std::replace(s.begin(), s.end(), '?', '.');
    cout << s << endl; return 0;
  }

  REP(i,n-1) {
    if (s[i] == '?' && s[i+1] == 'o') s[i] = '.';
    if (s[i] == 'o' && s[i+1] == '?') s[i+1] = '.';
  }

  vector<pair<char,int>> vs;
  REP(i,n) {
    if (vs.size() && vs.back().first == s[i]) vs.back().second++;
    else vs.emplace_back(s[i],1);
  }

  for(auto [c,cnt]: vs) if (c == '?') k -= (cnt+1)/2;

  if (k == 0) {
    for(auto [c,cnt]: vs) {
      if (c == '?' && cnt % 2) {
        REP(i,cnt) cout << (i%2 == 0 ? 'o' : '.');
      } else {
        REP(i,cnt) cout << c;
      }
    }
  } else {
    cout << s << endl;
  }
  return 0;
}
