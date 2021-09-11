#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin >> n;
  string ans = "1";
  REP(i,n) ans+="0";
  cout << ans << endl;
  return 0;
}