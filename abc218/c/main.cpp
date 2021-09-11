#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<pair<int,int>> sp,tp;

void solve() {
  REP(i,4) {
    sort(sp.begin(), sp.end());
    sort(tp.begin(), tp.end());

    // 原点に移動する
    int s_first = sp[0].first;
    int s_second = sp[0].second;
    REP(i,sp.size()) {
      sp[i] = { sp[i].first - s_first, sp[i].second - s_second };
    }
    int t_first = tp[0].first;
    int t_second = tp[0].second;
    REP(i,tp.size()) {
      tp[i] = { tp[i].first - t_first, tp[i].second - t_second };
    }

    if (sp == tp) { // 一致したら終了
      cout << "Yes" << endl;
      return;
    }

    // 90度回転させる
    REP(i,sp.size()) sp[i] = { -sp[i].second, sp[i].first };
  }
  cout << "No" << endl;
  return;
}

int main() {
  cin >> n;
  REP(i,n) REP(j,n) {
    char c; cin >> c;
    if (c == '#') sp.push_back({i,j});
  }
  REP(i,n) REP(j,n) {
    char c; cin >> c;
    if (c == '#') tp.push_back({i,j});
  }

  solve();
  return 0;
}