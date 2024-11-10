#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s; s += 'X';
  int cnt = 0, ans = 0;
  for(auto c: s) {
    if (c == 'O') cnt++;
    else { ans += cnt / k; cnt = 0; }
  }
  cout << ans << endl;
  return 0;
}