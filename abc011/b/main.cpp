#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  string s;
  cin >> s;
  if (s[0] >= 'a') s[0] += 'A' - 'a';
  FOR(i, 1, s.size()) if (s[i] < 'a') s[i] += 'a' - 'A';
  cout << s << endl;
}