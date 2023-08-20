#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> c(h);
  REP(i,h) cin >> c[i];
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) a[i][j] = c[i][j]-'a';

  const int m = 26;
  vector row(h,vector<int>(m));
  vector col(w,vector<int>(m));
  REP(i,h) REP(j,w) {
    row[i][a[i][j]]++;
    col[j][a[i][j]]++;
  }

  vector<bool> row_deleted(h),col_deleted(w);

  auto to_delete = [&](vector<int> x) {
    int tot = 0, k = 0;
    REP(j,m) {
      tot += x[j];
      if (x[j]) k++;
    }
    return tot >= 2 && k == 1;
  };
  auto del = [&](int i, int j) {
    if (row_deleted[i] || col_deleted[j]) return;
    row[i][a[i][j]]--;
    col[j][a[i][j]]--;
  };

  bool upd = true;
  while(upd) {
    upd = false;
    vector<int> del_row, del_col;
    REP(i,h) {
      if (row_deleted[i]) continue;
      if (to_delete(row[i])) del_row.push_back(i);
    }
    REP(j,w) {
      if (col_deleted[j]) continue;
      if (to_delete(col[j])) del_col.push_back(j);
    }
    for(int i: del_row) {
      REP(j,w) del(i,j);
      row_deleted[i] = true;
      upd = true;
    }
    for(int j: del_col) {
      REP(i,h) del(i,j);
      col_deleted[j] = true;
      upd = true;
    }
  }

  int ans = 0;
  REP(i,h) REP(j,w) {
    if (row_deleted[i] || col_deleted[j]) continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}