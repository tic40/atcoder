#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int ans = 0;
  for(char c: s) {
    if (c == 'v') ans+=1;
    else ans+=2;
  }
  cout << ans << endl;
  return 0;
}