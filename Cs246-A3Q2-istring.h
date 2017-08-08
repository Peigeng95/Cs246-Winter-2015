#ifndef __ISTRING_H__
#define __ISTRING_H__
#include <iostream>
#include <cstring>
struct iString{
  char * chars;
  unsigned int length;
  unsigned int capacity;
  iString();
  iString(const char *);
  iString(const iString&);
  iString &operator=(const iString&);
  ~iString();
};


// Add other declarations here:

std::istream &operator>>(std::istream &in, iString& str);
std::ostream &operator<<(std::ostream &out, const iString &str);
iString operator+(const iString &str1, const iString &str2);
iString operator+(const char *str1, const iString &str2);
iString operator+(const iString &str1, const char *str2);
int operator / (const iString &str1, const iString &str2);
iString operator % (const iString &str, int a);
#endif
