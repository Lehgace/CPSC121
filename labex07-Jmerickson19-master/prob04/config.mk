# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := lsa.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := lsa.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-readability-else-after-return,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-[modernize-loop-convert,-cppcoreguidelines-pro-bounds-constant-array-index,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-modernize-loop-convert,-hicpp-no-array-decay
