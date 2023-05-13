#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const string atc = "atcoder";
  string s,t; cin >> s >> t;
  map<char,int> ms,mt;
  REP(i,(int)s.size()) { ms[s[i]]++; mt[t[i]]++; }

  auto f = [&](map<char,int> ma, map<char,int> mb) {
    for(auto [k,v]: ma) {
      if (k == '@') continue;
      int d = v - mb[k];
      if (d <= 0) continue;
      if (atc.find(k) == string::npos) return false;
      if (mb['@'] < d) return false;
      mb['@'] -= d;
    }
    return true;
  };

  bool ok = f(ms,mt) && f(mt,ms);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}