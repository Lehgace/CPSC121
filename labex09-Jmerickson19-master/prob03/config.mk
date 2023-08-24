# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := player.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := player.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-modernize-pass-by-value,-modernize-use-default-member-init
