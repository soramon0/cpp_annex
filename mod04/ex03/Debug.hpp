#pragma once
#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

#if DEBUG
#define DEBUG_PRINT(x) std::cout << x
#else
#define DEBUG_PRINT(x)
#endif