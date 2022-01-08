#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  REP(i,n) {
    if (s[i] == 'a') continue;

    int x = s[i] - 'a';
    if (26-x <= k) {
      s[i] = 'a';
      k -= 26-x;
    }
  }

  s.back() = 'a' + (s.back() - 'a' + k)%26;
  cout << s << endl;

  return 0;
}