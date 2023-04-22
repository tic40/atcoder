#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;

  int x = 0;
  bool ok = false;
  REP(i,n) {
    if (s[i] == '|') x++;
    if (x == 1 && s[i] == '*') ok = true;
  }
  cout << (ok ? "in" : "out") << endl;
  return 0;
}