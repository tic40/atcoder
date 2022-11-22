#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int H,W,n,h,w;
  cin >> H >> W >> n >> h >> w;
  vector a(H,vector<int>(W));
  vector<int> cnt(n+1);
  int tot = 0;
  REP(i,H) REP(j,W) {
    cin >> a[i][j];
    if (cnt[a[i][j]] == 0) tot++;
    cnt[a[i][j]]++;
  }

  REP(i,H-h+1) {
    auto ncnt = cnt;
    int now = tot;

    auto add = [&](int x, int y){
      if (ncnt[a[x][y]] == 0) now++;
      ncnt[a[x][y]]++;
    };
    auto del = [&](int x, int y){
      ncnt[a[x][y]]--;
      if (ncnt[a[x][y]] == 0) now--;
    };

    REP(si,h) REP(sj,w-1) del(i+si,sj);
    REP(j,W-w+1) {
      REP(si,h) del(i+si,j+w-1);
      cout << now << " ";
      REP(si,h) add(i+si,j);
    }
    cout << endl;
  }

  return 0;
}