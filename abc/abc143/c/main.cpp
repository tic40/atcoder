#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, cnt = 1;
  string s;
  cin >> n >> s;
  char last = s[0];
  FOR(i, 1, n) {
    if (last != s[i]) cnt++;
    last = s[i];
  }
  cout << cnt << endl;
}