# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := student_profile.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := student_profile.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main 
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-pro-type-member-init,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-hicpp-member-init,-hicpp-no-array-decay
