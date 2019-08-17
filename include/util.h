#ifndef WIFIBUDDON_INCLUDE_UTIL_H_
#define WIFIBUDDON_INCLUDE_UTIL_H_

#include <cstdint>

namespace util {

inline char *allocLiteral(const char *src) {
  char *dest = (char *) malloc(sizeof(src));
  strcpy(dest, src);
  return dest;
}

}

#endif //WIFIBUDDON_INCLUDE_UTIL_H_
