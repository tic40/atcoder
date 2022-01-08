#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, _, min;
  cin >> n >> _;
  min = _;
  for (int i = 1; i < n; i++) {
    cin >> _;
    if (_ < min) min = _;
  }
  cout << min << endl;
}