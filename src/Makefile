CC = g++
CFLAGS = -c -Wall -Werror -Wextra -g -std=c++17
TEST_CFLAGS = -lgtest -lgmock -pthread
OBJ = $(CFILES:.cc=.o)
TESTS_OBJ = $(TESTS_CFILES:.cc=.o)
TESTS_CFILES = $(wildcard tests/*.cc)
CFILES = $(wildcard *.cc)
EXECUTABLE = tree
# LIB = s21_matrix_oop.a
# GCOV_FLAGS=--coverage -Wall -Werror -Wextra -std=c++17

# $^ вызов всех подцелей
# $< вызов первой подцели
# $@ вызов цели

all: test

%.o : %.cc
	$(CC) $(CFLAGS) $^ -o $@

test : $(TESTS_OBJ)
	$(CC) $^ -o test $(TEST_CFLAGS)
	./test
checkstyle:
	clang-format -style=google -n tests/*.cc
	clang-format -style=google -n tests/*.h
	clang-format -style=google -n array/*.tpp
	clang-format -style=google -n array/*.h
	clang-format -style=google -n BinaryTree/*.h
	clang-format -style=google -n *.h
	clang-format -style=google -n list/*.tpp
	clang-format -style=google -n list/*.h
	clang-format -style=google -n map/*.h
	clang-format -style=google -n multiset/*.h
	clang-format -style=google -n set/*.h
	clang-format -style=google -n vector/*.tpp
	clang-format -style=google -n vector/*.h
	clang-format -style=google -n stack/*.tpp
	clang-format -style=google -n stack/*.h
	clang-format -style=google -n queue/*.tpp
	clang-format -style=google -n queue/*.h


clean:
	rm -rf $(OBJ) $(TESTS_OBJ) test *.gcov *.gcno *.gcda *.info report $(EXECUTABLE)