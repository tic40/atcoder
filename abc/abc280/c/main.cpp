#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;

  int n = s.size();
  REP(i,n) {
    if (s[i] == t[i]) continue;
    cout << i+1 << endl;
    return 0;
  }
  cout << t.size() << endl;

  return 0;
}