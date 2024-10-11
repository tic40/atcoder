#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  int ans = 0;
  REP(i,n-2) {
    auto t = s.substr(i,3);
    if (t == "#.#") ans++;
  }
  cout << ans << endl;
  return 0;
}