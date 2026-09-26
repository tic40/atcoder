#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> pa;
  REP(i,n) {
    int a; cin >> a;
    if (pa.size() && pa.back().first == a) pa.back().second++;
    else pa.emplace_back(a,1);

    if (pa.back().second % 4 == 0) pa.pop_back();
  }

  int ans = 0;
  for(auto [_,v]: pa) ans += v;
  cout << ans << endl;
  return 0;
}
