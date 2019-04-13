// https://atcoder.jp/contests/apg4b/tasks/APG4b_cq
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, r;
  string op;
  bool error = false;
  cin >> A >> op >> B;

  if (op == "+") {
    r = A + B;
  } else if (op == "-") {
    r = A - B;
  } else if (op == "*") {
    r = A * B;
  } else if (op == "/") {
    if (B == 0) {
      error = true;
    } else {
      r = A / B;
    }
  } else {
    error = true;
  }
  error ? cout << "error" << endl : cout << r << endl;
}
