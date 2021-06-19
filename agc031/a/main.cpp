#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

int n;
string s;

int main() {
  cin >> n >> s;
  vector<ll> num(26);

  for (char c: s) num[c - 'a']++;

  ll ans = 1;
  REP(i,26) {
    // どの位置の文字cを選ぶか + 選ばない
    ans *= num[i] + 1;
    ans %= MOD;
  }

  // どれも選ばないケースが含まれるので -1 する
  ans--;
  cout << ans << endl;
  return 0;
}