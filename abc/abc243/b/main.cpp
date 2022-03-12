#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<int>a(n),b(n);
  set<int> sa,sb;
  REP(i,n) { cin >> a[i]; sa.insert(a[i]); }
  REP(i,n) { cin >> b[i]; sb.insert(b[i]); }

  int ans1 = 0;
  REP(i,n) ans1 += a[i] == b[i];

  int ans2 = 0;
  REP(i,n) if (a[i] != b[i] && sb.count(a[i]) > 0) ans2++;

  cout << ans1 << endl << ans2 << endl;
  return 0;
}