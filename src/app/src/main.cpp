#include <iostream>
#include <memory>
#include <lib1/HelloWriter.h>
//#include <boost/filesystem.hpp>

int main()
{
  using namespace std;
  auto writer = make_unique<HelloWriter>();
  auto x{17};
  auto f = [&]() -> void 
  {
    cout << writer->writeHello() << " " << " And hello from main!" << endl; 
  };

  f();
}
