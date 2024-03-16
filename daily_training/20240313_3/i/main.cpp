#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> c(n);
  REP(i,n) { cin >> c[i]; c[i]--; }
  REP(i,n) c.push_back(c[i]); // 実装を簡単にするため 2 周分用意しておく
  vector<int> tot(n);
  REP(i,n) tot[c[i]]++;

  vector<int> ball(n),box(n); // ボールと箱の分布
  int remain = m; // 箱の残り個数
  int ans = 0;

  auto add = [&](int i, int num) {
    ans -= min(tot[i], box[i]*k);
    remain += box[i];
    ball[i] += num;
    box[i] = (ball[i]+k-1) / k;
    remain -= box[i];
    ans += min(tot[i], box[i]*k);
  };

  // 尺取
  int r = 0;
  REP(l,n) {
    while(r < l+n && remain) {
      add(c[r], 1);
      r++;
    }
    cout << ans << endl;
    add(c[l], -1);
  }
  return 0;
}