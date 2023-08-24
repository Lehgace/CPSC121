# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := candy_shop.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := candy_shop.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-modernize-use-default-member-init,-cppcoreguidelines-avoid-magic-numbers,-hicpp-avoid-c-arrays,-modernize-use-nodiscard,-readability-magic-numbers,-cppcoreguidelines-avoid-c-arrays,-modernize-pass-by-value,-cppcoreguidelines-pro-bounds-constant-array-index,-modernize-avoid-c-arrays
