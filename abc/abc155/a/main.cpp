#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a==b && b==c) {
    cout << "No" << endl;
    return 0;
  }
  if (a == b || a == c || b == c) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
