#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  auto ans = regex_replace(s, regex(".*\\."), "");
  cout << ans << endl;
  return 0;
}