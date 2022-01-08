#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  int n = s.size();
  map<char, int> m;
  REP(i,n) m[s[i]]++;

  int a = m['a'];
  int b = m['b'];
  int c = m['c'];
  bool ok = true;
  if (1 < abs(a-b)) ok = false;
  if (1 < abs(a-c)) ok = false;
  if (1 < abs(b-c)) ok = false;

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}