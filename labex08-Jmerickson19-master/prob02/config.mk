# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := calculate_avg.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := calculate_avg.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-hicpp-use-auto,-cppcoreguidelines-owning-memory,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-readability-non-const-parameter,-modernize-use-auto
