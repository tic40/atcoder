#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  string op;
  int B;
  cin >> N >> A;
  bool error = false;

  for (int i = 0; i < N; i++) {
    cin >> op >> B;

    if (op == "+") {
      A += B;
    } else if (op == "-") {
      A -= B;
    } else if (op == "*") {
      A *= B;
    } else if (op == "/") {
      if (B == 0) {
        error = true;
        cout << "error" << endl;
        break;
      }
      A /= B;
    } else {
      // do nothing
    }

    cout << i+1 << ":" << A << endl;
  }
}
