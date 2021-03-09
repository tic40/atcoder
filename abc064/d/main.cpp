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

  int cursor = 0, addL = 0;
  REP(i,n) {
    if (s[i] == '(') cursor++;
    else cursor == 0 ? addL++ : cursor--;
  }

  string ans = string(addL, '(') + s + string(cursor, ')');
  cout << ans << endl;
  return 0;
}