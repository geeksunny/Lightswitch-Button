#ifndef LIGHTSWITCHBUTTON_INCLUDE_UTIL_H_
#define LIGHTSWITCHBUTTON_INCLUDE_UTIL_H_

#include <cstdint>

namespace util {

inline char *allocLiteral(const char *src) {
  char *dest = (char *) malloc(sizeof(src));
  strcpy(dest, src);
  return dest;
}

}

#endif //LIGHTSWITCHBUTTON_INCLUDE_UTIL_H_
