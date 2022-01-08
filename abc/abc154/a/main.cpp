#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  string s, t, u;
  int a, b,ans=0;
  cin >> s >> t >> a >> b >> u;
  if (s == u) a--;
  if (t == u) b--;
  cout << a << " " << b << endl;
}
