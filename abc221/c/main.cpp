#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<int> a(n),b(n);
  REP(i,n) a[i] = s[i]-'0';

  ll ans = 0;
  REP(i,a.size()) b[i] = i;
  do {
    REP(i,n) {
      ll l=0,r=0;
      REP(j,n) {
        if (j < i) {
          l*=10; l+=a[b[j]];
        } else {
          r*=10; r+=a[b[j]];
        }
      }
      ans = max(ans, l*r);
    }
  } while (next_permutation(b.begin(), b.end()));

  cout << ans << endl;
  return 0;
}