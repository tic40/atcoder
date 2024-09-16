#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector positions(n,vector<int>());

  REP(i,n) {
    int a; cin >> a; a--;
    positions[a].push_back(i);
  }
  // 番兵追加
  for(auto& v: positions) v.push_back(n);

  ll ans = 0;
  for (auto& pos : positions) {
    // 重複を許す組み合わせのため n+2-1C2 = n*(n+1)/2
    // 全体から x を含まない数を引くことで x を含む場合の数を求める(余事象)
    ll tot = (ll)n*(n+1)/2;
    int prev = -1;
    for(auto v: pos) {
      int start = prev + 1;
      int end = v - 1;
      int len = end - start + 1;
      tot -= (ll)len*(len+1)/2;
      prev = v;
    }
    ans += tot;
  }

  cout << ans << endl;
  return 0;
}