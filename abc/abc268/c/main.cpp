#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  vector<int> cnt(n);
  REP(i,n) {
    int d = (p[i] - i - 1 + n) % n;
    cnt[d % n]++;
    cnt[(d + 1) % n]++;
    cnt[(d + 2) % n]++;
  }

  int ans = *max_element(cnt.begin(),cnt.end());
  cout << ans << endl;
  return 0;
}