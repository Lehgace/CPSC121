# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := array_double.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := array_double.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-owning-memory,-modernize-use-nodiscard,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers,-modernize-pass-by-value,-fuchsia-overloaded-operator,-hicpp-special-member-functions,-google-explicit-constructor,-hicpp-explicit-conversions,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-hicpp-exception-baseclass
