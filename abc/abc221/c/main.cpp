#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<int> a(n),b(n);
  REP(i,n) a[i] = s[i]-'0';

  REP(i,n) b[i] = i;
  ll ans = 0;
  do {
    REP(i,n) {
      ll l=0,r=0;
      REP(i,n) {
        for(int j = 0; j < i; j++) l = l*10+a[b[j]];
        for(int j = i; j < n; j++) r = r*10+a[b[j]];
      }
      ans = max(ans, l*r);
    }
  } while (next_permutation(b.begin(), b.end()));

  cout << ans << endl;
  return 0;
}