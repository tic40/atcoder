#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;

  ll ans = 0;
  for(char c: s) ans = ans*26 + (c-'A'+1);
  cout << ans << endl;
  return 0;
}