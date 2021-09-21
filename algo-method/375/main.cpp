#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; string s;
  cin >> n >> s;
  string m = "IOI";
  int idx = 0;
  int ok = false;
  REP(i,n) {
    if (s[i] == m[idx]) idx++;
    if (idx == 3) { ok = true; break; }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}