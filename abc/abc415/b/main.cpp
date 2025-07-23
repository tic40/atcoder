#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<int> a;
  REP(i,(int)s.size()) if (s[i] == '#') a.push_back(i+1);

  int x = 0;
  for(auto v: a) {
    cout << v;
    if (x == 0) cout << ",";
    else cout << endl;
    x ^= 1;
  }
  return 0;
}