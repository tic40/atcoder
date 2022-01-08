#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a << endl;
    return 0;
  }
  double k = (a + b) / 2.0;
  if (ceil(k) == floor(k)) {
    cout << int(k) << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}