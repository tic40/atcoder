#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  cout << a << b << c << endl;
  int sum = a+b+c;
  if (sum >= 22) {
    cout << "bust";
  } else {
    cout << "win";
  }
  cout << endl;
}