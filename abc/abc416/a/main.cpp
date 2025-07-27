#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,l,r; string s;
  cin >> n >> l >> r >> s;
  l--; r--;
  bool ok = true;
  for(int i = l; i <= r; i++) {
    if (s[i] != 'o') ok = false;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}