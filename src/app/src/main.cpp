#include <iostream>
#include <string>
#include <memory>
#include <lib1/HelloWriter.h>
#include <thread>
#include <vector>
#include <algorithm>
//#include <boost/filesystem.hpp>

std::vector<std::string> explode(const std::string& s, const char& c)
{
  std::string buff{ "" };
  std::vector<std::string> v;

  for (auto n : s)
  {
    if (n != c) buff += n; else
      if (n == c && buff != "") { v.push_back(buff); buff = ""; }
  }
  if (buff != "") v.push_back(buff);

  return v;
}

int main()
{
  using namespace std;
  auto writer = make_unique<HelloWriter>();
  auto x{17};
  auto f = [&]() -> void 
  {
    cout << writer->writeHello() << " " << " And hello from main on thread id: " << std::this_thread::get_id() << endl;
  };
  cout << "Starting program on thread: " << std::this_thread::get_id() << endl;
  thread t(f);
  t.join();
  auto hwThreads = std::thread::hardware_concurrency();

  auto sumSomeInts = [](unsigned long long numberOfAdditions)
  { 
    cout << "---sumSomeInts starts with " << numberOfAdditions << " numberOfAdditions on thread: " << std::this_thread::get_id() << endl;
    long long sum = 0;
    for(unsigned int i = 1 ; i <= numberOfAdditions ; i++) 
    {
      sum += i;
    }
    cout << "sumSomeInts done on thread: " << std::this_thread::get_id() << " with total sum of " << sum << "." << endl;
  };
 
  cout << "Enter " << hwThreads << " big numbers with space in between, e.g. 23452346 67572 ..." << endl;
  string line;
  getline(cin, line);
  auto numbersArray = explode(line, ' ');

  vector<thread> threadsVector;
  for(const auto numberString : numbersArray) 
  {
    auto number = stoull(numberString, nullptr, 0);
    threadsVector.push_back(thread(sumSomeInts, number));
  }
  
  for_each(begin(threadsVector), end(threadsVector), [](thread& t) { t.join(); });

  system("pause");
}
