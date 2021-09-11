#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s = "01001";
  int ans = 0;
  for(int c: s) if (c == '1') ans++;
  cout << ans << endl;
  return 0;
}