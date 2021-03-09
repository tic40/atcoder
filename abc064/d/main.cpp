#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int add_l = 0, add_r = 0, cursor = 0;
  REP(i,n) {
    if (s[i] == '(') {
      cursor++;
    } else {
      cursor == 0 ? add_l++ : cursor--;
    }
  }
  add_r = cursor;

  string ans = string(add_l, '(') + s + string(add_r, ')');
  cout << ans << endl;

  return 0;
}