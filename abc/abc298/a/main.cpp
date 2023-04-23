#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  bool ok = false;
  REP(i,n) {
    if (s[i] == 'x') { cout << "No" << endl; return 0; }
    if (s[i] == 'o') ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}