#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a,b;
  cin >> a >> b;
  string s(b, '0'+a);
  string t(a, '0'+b);
  cout << min(s,t) << endl;
}
