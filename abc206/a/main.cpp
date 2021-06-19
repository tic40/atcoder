#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  double n;
  cin >> n;
  n *= 1.08;
  n = floor(n);

  if (n < 206) cout << "Yay!" << endl;
  else if (206 == n) cout << "so-so" << endl;
  else cout << ":(" << endl;

  return 0;
}