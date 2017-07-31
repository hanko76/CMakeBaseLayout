#include <string>
#include <boost/core/noncopyable.hpp>
//#include "lib1_export.h"

//class lib1_EXPORT HelloWriter : private boost::noncopyable
class HelloWriter
{
public:
  HelloWriter();
  ~HelloWriter();
  // @returns "Hello from HelloWriter!"
  std::string writeHello() const;
};
