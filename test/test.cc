#include <iostream>
#include <string>
using namespace std;
class A {
public:
  A() {}
  A(int a) {}
  A(A &a) {}
  A(A &&a) {}
};
int main() {
  A a;
  a(A(1));
  return 0;
}