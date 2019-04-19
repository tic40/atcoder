#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  double total = 0;
  cin >> n >> k;
  vector<double> r(n);
  for (int i = 0; i < n; i++) cin >> r.at(i);
  sort(r.begin(), r.end());
  for (int i = n - k; i < n; i++) total = (total + r.at(i)) / 2;
  printf("%.6f\n", total);
}