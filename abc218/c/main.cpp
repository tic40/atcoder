#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

void move_to_origin(vector<P> &p) {
  sort(p.begin(), p.end());
  auto [a,b] = p[0];
  for (auto &v: p) v = { v.first-a, v.second-b };
  return;
}

void solve(vector<P> sp, vector<P> tp) {
  // 原点に平行移動
  move_to_origin(sp);
  move_to_origin(tp);

  REP(i,4) {
    // 一致したら終了
    if (sp == tp) { cout << "Yes" << endl; return; }

    // 90度回転させる
    for (auto &v: sp) v = { -v.second, v.first };
    move_to_origin(sp);
  }

  cout << "No" << endl;
  return;
}

int main() {
  int n; cin >> n;

  vector<P> sp,tp;
  REP(i,n) REP(j,n) {
    char c; cin >> c;
    if (c == '#') sp.emplace_back(P{i,j});
  }
  REP(i,n) REP(j,n) {
    char c; cin >> c;
    if (c == '#') tp.emplace_back(P{i,j});
  }

  solve(sp,tp);
  return 0;
}