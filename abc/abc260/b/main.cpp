#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,x,y,z; cin >> n >> x >> y >> z;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  vector<P> ap(n),bp(n),abp(n);
  REP(i,n) {
    ap[i] = {a[i],-i};
    bp[i] = {b[i],-i};
    abp[i] = {a[i]+b[i],-i};
  }
  sort(ap.rbegin(),ap.rend());
  sort(bp.rbegin(),bp.rend());
  sort(abp.rbegin(),abp.rend());

  set<int> st;
  REP(i,x) st.insert(-ap[i].second);

  REP(i,n) {
    if ((int)st.size()-x == y) break;
    st.insert(-bp[i].second);
  }
  REP(i,n) {
    if ((int)st.size()-(x+y) == z) break;
    st.insert(-abp[i].second);
  }

  for(int v: st) cout << v+1 << endl;
  return 0;
}