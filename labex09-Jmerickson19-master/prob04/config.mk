# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := student.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := student.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-modernize-pass-by-value,-cppcoreguidelines-pro-type-member-init,-cppcoreguidelines-pro-bounds-constant-array-index,-hicpp-member-init
