# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := super_enemy.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := super_enemy.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-readability-magic-numbers,-modernize-use-nodiscard,-cppcoreguidelines-avoid-magic-numbers
