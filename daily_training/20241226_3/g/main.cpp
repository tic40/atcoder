#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  string t;
  REP(i,n) {
    t.push_back(s[i]);
    if (t.size() < 3) continue;
    if (t.substr(t.size()-3) == "ABC") REP(i,3) t.pop_back();
  }
  cout << t << endl;
  return 0;
}