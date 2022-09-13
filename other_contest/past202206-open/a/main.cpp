#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  double x,a,b,c;
  cin >> x >> a >> b >> c;

  double ta = x/a + c;
  double tb = x/b;
  if (ta < tb) cout << "Hare";
  else if (ta == tb) cout << "Tie";
  else cout << "Tortoise";

  return 0;
}