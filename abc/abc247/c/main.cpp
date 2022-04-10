#include <bits/stdc++.h>
using namespace std;

void f(int x) {
  if (x == 0) return;
  f(x-1);
  cout << x << " ";
  f(x-1);
}

int main() {
  int n; cin >> n;
  f(n);
  return 0;
}