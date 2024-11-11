#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;
  reverse(s.begin(),s.end());

  int mx = n+50; // 最大桁数を大きめに取る
  vector<ll> d(mx); // 各桁の値
  ll sum = 0;
  // 上の桁から順に処理
  for(int i = n-1; i >= 0; i--) {
    sum += (s[i]-'0') * (n-i);
    d[i] = sum;
  }

  REP(i,mx-1) {
    d[i+1] += d[i]/10;
    d[i] %= 10;
  }

  // 先頭の 0 を取り除く
  while(d.back() == 0) d.pop_back();
  reverse(d.begin(),d.end());
  for(auto v: d) cout << v;
  return 0;
}