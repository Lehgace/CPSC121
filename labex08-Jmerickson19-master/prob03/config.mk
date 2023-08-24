# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := add_array.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := add_array.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-pro-bounds-constant-array-index,-modernize-loop-convert,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-hicpp-no-array-decay,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-readability-non-const-parameter
