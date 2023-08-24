#ifndef _ARRAY_DOUBLE_HPP_
#define _ARRAY_DOUBLE_HPP_

#include <sstream>
#include <string>

class Exception
{
private:
  std::string message_;

protected:
  Exception() : Exception("") {}

public:
  Exception(const std::string & msg) : message_(msg) {}
  std::string message() const { return message_; }
  void set_message(const std::string & msg) { message_ = msg; }
};

class IndexOutOfRangeException : public Exception
{
public:
  IndexOutOfRangeException(int ix, int size)
  {
    std::stringstream ss;
    ss << "Invalid index " << ix << " for an array with " << size << " element"
       << (size == 1 ? "" : "s") << ". Value must be between 0 and " << size - 1
       << '.';
    set_message(ss.str());
  }
};

class InvalidArrayLengthException : public Exception
{
public:
  InvalidArrayLengthException(int elements)
  {
    std::stringstream ii;
    ii << "Invalid number of elements (" << elements << ")."
       << " Value must be a positive integer.";
    set_message(ii.str());
  }
};

class ArrayDouble
{
private:
  double * array_;
  int num_;

public:
  ArrayDouble(int num);
  ~ArrayDouble();

  double & operator[](int ix) const;
  void display() const;
};

#endif
