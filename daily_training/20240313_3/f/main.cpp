#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = t.size();
  s += '_';
  REP(i,n) {
    if (s[i] != t[i]) { cout << i+1 << endl; break; }
  }
  return 0;
}