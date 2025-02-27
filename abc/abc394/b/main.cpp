#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  sort(s.begin(),s.end(),[&](string a, string b){ return a.size() < b.size(); });
  for(auto v: s) cout << v;
  return 0;
}
