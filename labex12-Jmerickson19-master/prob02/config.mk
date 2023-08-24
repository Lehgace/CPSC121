# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := weapons.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := weapons.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-modernize-use-nodiscard,-modernize-pass-by-value,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-msc30-c,-cert-msc50-cpp
