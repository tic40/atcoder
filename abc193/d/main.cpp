#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int k;
string S,T;
vector<int> s(5),t(5);

ll score(vector<int> x) {
  ll score = 0;
  vector<int> cnt(10);
  for(int v: x) cnt[v]++;
  for(int i = 1; i < 10; i++)  score += i * pow(10, cnt[i]);
  return score;
}

int main() {
  cin >> k >> S >> T;
  REP(i,4) {
    s[i] = S[i]-'0';
    t[i] = T[i]-'0';
  }
  vector<int> cnt(10, k);
  REP(i,4) { cnt[s[i]]--; cnt[t[i]]--; }

  ll win = 0;
  for(int i = 1; i < 10; i++) {
    for(int j = 1; j < 10; j++) {
      s.back() = i;
      t.back() = j;
      if (score(s) <= score(t)) continue;
      win += cnt[i] * (cnt[j] - (i == j));
    }
  }

  cout << win << endl;
  ll rem = 9*k-8;
  double ans = double(win) / rem / (rem-1);
  cout << ans << endl;
  return 0;
}