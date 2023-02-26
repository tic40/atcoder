#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  REP(i,n) if (isupper(s[i])) { cout << i+1 << endl; break; }
  return 0;
}