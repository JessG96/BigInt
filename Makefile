# Variables
CPP  = clang++
OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

# For milestone 2 add: test_add test_subscript
# For milestone 3 add: test_times_10 test_times_digit test_multiply
TESTS = test_default_ctor test_int_ctor test_equal test_c_str_ctor test_add test_subscript

###############################################################
# The first rule is run if only make is typed
msg:
        @echo 'Targets are:'
        @echo '  tests:'
        @echo '  add:'
        @echo '  multiply:'
        @echo '  factorial:'
        @echo '  clean:'

###############################################################
# Build and run all tests and output demonstration
#
tests: $(TESTS)
        ./test_default_ctor
        ./test_int_ctor
        ./test_equal
        ./test_c_str_ctor
#Milestone 2 - remove #
        ./test_add
        ./test_subscript
#Milestone 3
        #./test_times_10
         #./test_times_digit
        #./test_multiply

###############################################################
# Build and run Milestone 2
add: milestone2
        ./add

###############################################################
# Build and run Milestone 3
multiply: milestone3
        ./multiply

###############################################################
# Build and run factorial
factorial: extra
        ./factorial

###############################################################
# Compile bigint type
bigint.o: bigint.hpp bigint.cpp
        $(CPP) $(OPTS) -c bigint.cpp
        ###############################################################
# Compile and run all tests - uses a wild card.
test_%: bigint.o test_%.o
        $(CPP) $(OPTS) -o test_$* bigint.o test_$*.o

test_%.o: bigint.hpp test_%.cpp
        $(CPP) $(OPTS) -c test_$*.cpp



###############################################################
# For milestone 2
milestone2: add.o bigint.o
        $(CPP) $(OPTS) -o add add.o bigint.o

add.o: bigint.hpp add.cpp
        $(CPP) $(OPTS) -c add.cpp

###############################################################
# For milestone 3
milestone3: multiply.o bigint.o
        $(CPP) $(OPTS) -o multiply multiply.o bigint.o
        multiply.o: bigint.hpp multiply.cpp
        $(CPP) $(OPTS) -c multiply.cpp

###############################################################
# Factorial
extra: factorial.o bigint.o
        $(CPP) $(OPTS) -o factorial factorial.o bigint.o

factorial.o: bigint.hpp factorial.cpp
        $(CPP) $(OPTS) -c factorial.cpp


###############################################################
clean:
        rm -f *.o
        rm -f $(TESTS)
        rm -f multiply add factorial


