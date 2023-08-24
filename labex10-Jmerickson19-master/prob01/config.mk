# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := car_comp.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := car_comp.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-modernize-use-nodiscard,-modernize-pass-by-value,-hicpp-explicit-conversions,-readability-magic-numbers,-google-explicit-constructor,-hicpp-use-equals-default,-modernize-use-equals-default
