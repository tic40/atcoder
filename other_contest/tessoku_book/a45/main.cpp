#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  char c; cin >> c;
  string s; cin >> s;

  int sum = 0;
  REP(i,n) {
    if (s[i] == 'B') sum+=1;
    if (s[i] == 'R') sum+=2;
  }

  bool ok = false;
  if (sum % 3 == 0 && c == 'W') ok = true;
  if (sum % 3 == 1 && c == 'B') ok = true;
  if (sum % 3 == 2 && c == 'R') ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}