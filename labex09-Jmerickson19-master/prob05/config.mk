# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := list.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := list.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-hicpp-special-member-functions,-google-explicit-constructor,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-hicpp-explicit-conversions,-cppcoreguidelines-special-member-functions
