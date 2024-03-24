#include <iostream>
#include <string>
using namespace std;

int main() {
  string Fn, Sn;
  int size;

  cout << "First number  >> ";

  cin >> Fn;
  cout << "Second number >> ";

  cin >> Sn;

  if (Fn.size() >= Sn.size()) {
    size = Fn.size() + 1;
  } else {
    size = Sn.size() + 1;
  }

  int sum[size];
  int sub[size];
  int Fdigit[size];
  int Sdigit[size];

  // 빈 공간에 0을 넣는 과정
  for (int i = 0; i < size; i++) {
    sum[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    sub[i] = 0;
  }
  for (int i = 0; i < size - Fn.size(); i++) {
    Fdigit[i] = 0;
  }
  for (int i = 0; i < size - Sn.size(); i++) {
    Sdigit[i] = 0;
  }

  // 본래 숫자를 넣는 과정
  for (int i = size - Fn.size(); i < size; i++) {
    Fdigit[i] = Fn[i - (size - Fn.size())] - '0';
  }
  for (int i = size - Sn.size(); i < size; i++) {
    Sdigit[i] = Sn[i - (size - Sn.size())] - '0';
  }

  // 숫자를 더하는 과정
  for (int i = size - 1; i >= 0; i--) {
    sum[i] = sum[i] + Fdigit[i] + Sdigit[i];
    if (sum[i] >= 10) {
      sum[i] -= 10;
      sum[i - 1] += 1;
    }
  }

  // 덧셈 결과 출력
  cout << "sum           >> ";
  for (int i = 0; i < size; i++) {
    if (i == 0 && sum[i] == 0) {
      continue;
    }
    cout << sum[i];
  }

  cout << endl;

  // 숫자를 빼는 과정
  if (Fn.size() >= Sn.size()) { // First Number가 Second Number보다 크거나 같을 때
    for (int i = size - 1; i >= 0; i--) {
      sub[i] = Fdigit[i] - Sdigit[i] + sub[i];
      if (sub[i] < 0) {
        sub[i] += 10;
        sub[i - 1] -= 1;
      }
    }
  } else { // Firist Number가 Second Number보다 작을 때
    for (int i = size - 1; i >= 0; i--) {
      sub[i] = Sdigit[i] - Fdigit[i] + sub[i];
      if (sub[i] < 0) {
        sub[i] += 10;
        sub[i - 1] -= 1;
      }
    }

    sub[0] = 1;
  }

  // 뺄셈 결과 출력
  cout << "sub           >> ";

  
  if (sub[0] == 1) {
    cout << "-";
    sub[0] = 0;
  }

  int space = 0;
  for (int i = 0; i < size; i++) {
    if (sub[i] != 0) {
      space = i;
      break;
    }
  }

  if (space == 0) {
    cout << 0 << endl;
  } else {
    for (int i = space; i < size; i++) {
      cout << sub[i];
    }
  }
  
  cout << endl;

  return 0;
}