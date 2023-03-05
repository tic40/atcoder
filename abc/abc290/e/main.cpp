#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// nC2: n個から2個選ぶ
ll c2(ll n) { return n * (n-1) / 2; }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }
  vector<int> cnt(n);
  REP(i,n) cnt[a[i]]++;

  ll same = 0;
  REP(i,n) same += c2(cnt[i]);

  auto del = [&](int x) {
    same -= c2(cnt[x]);
    cnt[x]--;
    same += c2(cnt[x]);
  };

  ll ans = 0;
  REP(i,n) {
    int l = i, r = n-1-i;
    if (l >= r) break;
    ans += c2(r-l+1) - same;
    del(a[l]); del(a[r]);
  }

  cout << ans << endl;
  return 0;
}