#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int m = 2000;
  vector sky(m+1,vector<int>(m+1));
  vector one(m+1,vector<int>(m+1));
  vector<tuple<int,int,int,int>> clouds;

  int n; cin >> n;
  // imos 2次元累積和 
  REP(i,n) {
    int u,d,l,r; cin >> u >> d >> l >> r;
    u--; l--;
    sky[u][l]++;
    sky[u][r]--;
    sky[d][l]--;
    sky[d][r]++;
    clouds.emplace_back(u,d,l,r);
  }
  REP(i,m) REP(j,m) sky[i+1][j] += sky[i][j];
  REP(i,m) REP(j,m) sky[i][j+1] += sky[i][j];
  
  // 雲一つが覆っているマスを集計
  REP(i,m) REP(j,m) one[i+1][j+1] = (sky[i][j] == 1);
  // 累積和
  REP(i,m) REP(j,m+1) one[i+1][j] += one[i][j];
  REP(i,m+1) REP(j,m) one[i][j+1] += one[i][j];
  
  int base = 0;
  REP(i,m) REP(j,m) if (sky[i][j] == 0) base++;
  
  for(auto [u,d,l,r] : clouds) {
    int dif = one[d][r] - one[d][l] - one[u][r] + one[u][l];
    cout << base+dif << endl;
  }
  return 0;
}