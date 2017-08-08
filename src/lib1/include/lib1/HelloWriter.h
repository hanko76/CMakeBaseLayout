#include <string>
#include <boost/core/noncopyable.hpp>
#include "lib1_export.h"

class LIB1_EXPORT HelloWriter : private boost::noncopyable
{
public:
  // @returns "Hello from HelloWriter!"
  std::string writeHello() const;
};
