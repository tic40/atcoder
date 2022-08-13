#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int l,r; cin >> l >> r;
  l--; r--;
  string s = "atcoder";
  cout << s.substr(l,r-l+1) << endl;
  return 0;
}