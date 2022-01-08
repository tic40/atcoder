#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w,n;
vector<int> a,b;

void solve() {
  map<int,int> mpa,mpb;
  REP(i,n) {
    mpa[a[i]] = 0;
    mpb[b[i]] = 0;
  }

  int cnt = 1;
  for(auto& v: mpa) {
    v.second += cnt;
    cnt++;
  }
  cnt = 1;
  for(auto& v: mpb) {
    v.second += cnt;
    cnt++;
  }

  REP(i,n) cout << mpa[a[i]] << " " << mpb[b[i]] << endl;
  return;
}

int main() {
  cin >> h >> w >> n;
  a.resize(n);
  b.resize(n);
  REP(i,n) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  solve();
  return 0;
}