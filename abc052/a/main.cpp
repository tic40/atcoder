#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if (a*b > c*d) cout << a*b;
  else cout << c*d;
  cout << endl;
}
