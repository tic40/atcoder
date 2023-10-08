#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  vector<string> s(n);
  REP(i,m) cin >> a[i];
  REP(i,n) cin >> s[i];

  vector<int> score(n);
  REP(i,n) {
    REP(j,m) if (s[i][j] == 'o') score[i] += a[j];
    score[i] += (i+1);
  }

  vector<P> p(m);
  REP(i,m) p[i] = {a[i],i};
  sort(p.rbegin(),p.rend());
  vector<int> order(m);
  REP(i,m) order[i] = p[i].second;

  int mx = *max_element(score.begin(),score.end());
  REP(i,n) {
    int ans = 0;
    for(auto j: order) {
      if (score[i] >= mx) break;
      if (s[i][j] == 'o') continue;
      score[i] += a[j];
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}