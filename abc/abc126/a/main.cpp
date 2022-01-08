#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  s[k-1] = tolower(s[k-1]);
  cout << s << "\n";
}