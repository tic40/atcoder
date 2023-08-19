#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s;
  cin >> s;
  const string t = "aeiou";
  for(auto c: s) {
    bool skip = false;
    for(auto x: t) { if (c == x) skip = true; }
    if (skip) continue;
    cout << c;
  }
  cout << endl;
  return 0;
}