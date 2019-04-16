#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int maxi = max(max(A, B), C);
  int mini = min(min(A, B), C);
  cout << maxi - mini << endl;
}
