#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,k; cin >> n >> k;
  vector<int> l(n),r(n);
  REP(i,n) cin >> l[i] >> r[i];
  REP(i,n) r[i]+=k;

  const int mx = 86400 + k + 1;
  vector<P> p1(n),p2(n);
  REP(i,n) {
    p1[i] = {r[i],l[i]};
    p2[i] = {l[i],r[i]};
  }
  sort(p1.begin(),p1.end());
  sort(p2.rbegin(),p2.rend());
  vector<int> cntL(mx), cntR(mx);

  // 左から区間スケジューリング
  int now = 0, cnt = 0;
  REP(i,n) {
    auto [nr,nl] = p1[i];
    if (nl < now) continue;
    now = nr; cnt++;
    cntL[now] = cnt;
  }

  // 右から区間スケジューリング
  now = mx, cnt = 0;
  REP(i,n) {
    auto [nl,nr] = p2[i];
    if (now < nr) continue;
    now = nl; cnt++;
    cntR[now] = cnt;
  }

  REP(i,mx-1) cntL[i+1] = max(cntL[i+1], cntL[i]);
  reverse(cntR.begin(),cntR.end());
  REP(i,mx-1) cntR[i+1] = max(cntR[i+1], cntR[i]);
  reverse(cntR.begin(),cntR.end());

  REP(i,n) cout << cntL[l[i]] + 1 + cntR[r[i]] << endl;
  return 0;
}