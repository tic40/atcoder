#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  int n2 = n*2;
  // a は2週分確保しておく
  vector<int> a(n2);
  REP(i,n) cin >> a[i];
  REP(i,n) a[n+i] = a[i];

  // 累積和
  vector<int> s(n2+1);
  REP(i,n2) s[i+1] = (s[i] + a[i]) % m;

  ll ans = 0;
  vector<int> cnt(m+1);
  REP(i,n-1) cnt[s[i+1]]++;
  int now = 0;
  REP(i,n) {
    ans += cnt[now];
    now += a[i];
    now %= m;
    cnt[now]--;
    cnt[s[i+n]]++;
  }
  cout << ans << endl;
  return 0;
}