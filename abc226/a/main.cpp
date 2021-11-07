#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  /*
  double n; cin >> n;
  cout << round(n) << endl;
  */
  // 誤差を考慮
  int a,b;
  scanf("%d.%d", &a, &b);
  if (b/100 >= 5) a++;
  cout << a << endl;

  return 0;
}
