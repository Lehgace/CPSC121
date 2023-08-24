# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := min.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := min.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-hicpp-no-array-decay,-readability-non-const-parameter,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cppcoreguidelines-avoid-c-arrays,-hicpp-avoid-c-arrays,-modernize-avoid-c-arrays
