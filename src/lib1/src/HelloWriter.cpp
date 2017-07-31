#include <lib1/HelloWriter.h>

HelloWriter::HelloWriter() {};
HelloWriter::~HelloWriter() {};

std::string HelloWriter::writeHello() const
{
  return "Hello from HelloWriter!"; 
}
