#include <iostream>
#include <memory>
#include <lib1/HelloWriter.h>
#include <thread>
//#include <boost/filesystem.hpp>

int main()
{
  using namespace std;
  auto writer = make_unique<HelloWriter>();
  auto x{17};
  auto f = [&]() -> void 
  {
    cout << writer->writeHello() << " " << " And hello from main on thread id: " << std::this_thread::get_id() << endl;
  };
  cout << "Starting program on thread: " << std::this_thread::get_id() << endl;;
  thread t(f);
  t.join();
 
  system("pause");
}
