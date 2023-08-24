# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := pet.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := pet.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-modernize-use-nodiscard,-readability-magic-numbers,-modernize-use-default-member-init,-cppcoreguidelines-pro-bounds-constant-array-index,-modernize-avoid-c-arrays,-cppcoreguidelines-avoid-magic-numbers,-hicpp-avoid-c-arrays,-cppcoreguidelines-avoid-magic-numbers,-modernize-pass-by-value,-cppcoreguidelines-avoid-c-arrays
