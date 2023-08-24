# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := find_number.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := find_number.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-google-explicit-constructor,-hicpp-special-member-functions,-google-explicit-constructor,-hicpp-explicit-conversions,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-hicpp-explicit-conversions,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-modernize-use-nodiscard,-cppcoreguidelines-owning-memory
