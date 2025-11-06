#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;

  ll ans = 0;
  vector<int> dist(n+2);
  set<P> st;
  st.emplace(0,0);
  st.emplace(INF,n+1); // 番兵
  dist[0] = INF;
  ans += INF;

  auto update = [&](int i, int d) -> void {
    ans -= dist[i];
    dist[i] = min(dist[i],d);
    ans += dist[i];
  };

  for(int i = 1; i <= n; i++) {
    int x; cin >> x;

    auto it = st.emplace(x,i).first;
    int dprev = x - (*prev(it)).first;
    int dnext = (*next(it)).first - x;
    dist[i] = min(dprev, dnext);
    ans += dist[i];

    update((*prev(it)).second, dprev);
    update((*next(it)).second, dnext);

    cout << ans << endl;
  }
  return 0;
}