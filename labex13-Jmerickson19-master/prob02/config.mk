# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := pair_class_template.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := 
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-modernize-use-nodiscard
