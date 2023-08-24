# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := statistics_calculator.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := statistics_calculator.cpp
# File containing main
DRIVER        := main.cpp
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-modernize-use-nodiscard,-bugprone-too-small-loop-variable,-modernize-loop-convert,-hicpp-use-auto
