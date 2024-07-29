#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using ll = long long;

int main() {
  int n; ll x,y;
  cin >> n >> x >> y;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  vector<P> pa(n),pb(n);
  REP(i,n) {
    pa[i] = {a[i],b[i]};
    pb[i] = {b[i],a[i]};
  }

  sort(pa.rbegin(),pa.rend());
  sort(pb.rbegin(),pb.rend());

  auto f = [&](vector<P>& a, ll x) {
    ll now = 0;
    REP(i,(int)a.size()) {
      now += a[i].first;
      if (now > x) return i+1;
    }
    return (int)a.size();
  };

  cout << min(f(pa,x),f(pb,y)) << endl;
  return 0;
}