#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  cout << "A:" << flush;
  while(A > 0) {
    cout << "]" << flush;
    A--;
  }
  cout << endl;
  cout << "B:" << flush;
  while(B > 0) {
    cout << "]" << flush;
    B--;
  }
  cout << endl;
}
