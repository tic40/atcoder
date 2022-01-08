#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;
using ll = long long;

ll n;
string s;

ll solve1() {
  vector<int> maru(n), batsu(n);

  int cur = INF;
  for (int i = n-1; 0 <= i; i--) {
    if (s[i] == 'o') cur = i;
    maru[i] = max(i, cur);
  }
  cur = INF;
  for (int i = n-1; 0 <= i; i--) {
    if (s[i] == 'x') cur = i;
    batsu[i] = max(i, cur);
  }

  ll ans = 0;
  REP(i,n-1) {
    if (s[i] == 'o') {
      if (batsu[i] == INF) continue;
      ans += n - batsu[i];
    } else {
      if (maru[i] == INF) continue;
      ans += n - maru[i];
    }
  }

  return ans;
}

// ランレングス圧縮
ll solve2() {
  vector<pair<char,ll>> v;
  int cnt = 0;

  REP(i,n) {
    cnt++;
    if (i == n-1 || s[i+1] != s[i]) {
      v.push_back({ s[i], cnt });
      cnt = 0;
    }
  }

  ll exclude = 0;
  REP(i,v.size()) {
    exclude += v[i].second * (v[i].second+1) / 2;
  }

  return n * (n+1) / 2 - exclude;
}

int main() {
  cin >> n >> s;
  cout << solve2() << endl;

 return 0;
}