#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  bool f = false;
  for(auto c: s) {
    if (c == '|') { f = !f; continue; }
    if (f) continue;
    cout << c;
  }
  return 0;
}