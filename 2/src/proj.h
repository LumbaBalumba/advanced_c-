#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define PROJ_EXPORT __declspec(dllexport)
#else
  #define PROJ_EXPORT
#endif

PROJ_EXPORT void proj();
PROJ_EXPORT void proj_print_vector(const std::vector<std::string> &strings);
