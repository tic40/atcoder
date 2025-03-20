#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector<int> score(n);
  iota(score.begin(),score.end(),1);
  REP(i,n) REP(j,m) if (s[i][j] == 'o') score[i] += a[j];
  int mx = *max_element(score.begin(),score.end());

  vector<int> b(m);
  iota(b.begin(),b.end(),0);
  sort(b.begin(),b.end(),[&](int x, int y) { return a[x] > a[y]; });
  REP(i,n) {
    int ans = 0, now = score[i];
    REP(j,m) if (now < mx && s[i][b[j]] == 'x') {
      now += a[b[j]];
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
