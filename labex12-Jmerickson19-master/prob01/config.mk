# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := car.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := car.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-owning-memory,-modernize-use-nodiscard,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers,-modernize-pass-by-value
