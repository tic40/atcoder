#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector<P> score;
  REP(i,n) score.emplace_back(0,-i);
  REP(j,m) {
    int cnt = 0;
    REP(i,n) if (s[i][j] == '0') cnt++;
    char c = cnt <= n/2 ? '0' : '1';
    REP(i,n) if (s[i][j] == c) score[i].first++;
  }

  score.emplace_back(-1,-1);
  sort(score.rbegin(),score.rend());
  REP(i,n) {
    cout << -score[i].second+1 << " ";
    if (score[i].first != score[i+1].first) break;
  }
  return 0;
}