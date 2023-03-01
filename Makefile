##
## MARBLE
## 
## Project by:
## Alexis "Norech" CHERON
##

CC = gcc

AR = ar rc

CFLAGS = -W -Wall -Werror -pedantic -I./include -I./exercices

CFLAGS_TEST = ${CFLAGS} --coverage

LFLAGS = 

LFLAGS_TEST = ${LFLAGS} -lcriterion

TESTDIR = tests

SRC =	src/json/lexer/token_array_close.c \
	src/json/lexer/token_array_open.c \
	src/json/lexer/token_object_close.c \
	src/json/lexer/token_object_open.c \
	src/json/lexer/token_comma.c \
	src/json/lexer/token_float.c \
	src/json/lexer/token_bool.c \
	src/json/lexer/token_integer.c \
	src/json/lexer/token_null.c \
	src/json/lexer/token_pair_separator.c \
	src/json/lexer/token_string.c \
	src/json/lexer/token_whitespace.c \
	src/json/lexer/is_char.c \
	src/json/lexer/is_word.c \
	src/json/parser/parse_json_array.c \
	src/json/parser/parse_json_object.c \
	src/json/parser/parse_json_value.c \
	src/json/parser.c \
	src/util/lexer_helpers.c \
	src/util/add_char_to_string.c \
	src/util/expand_string.c \
	src/util/free_values.c

TEST_FILES = 	${TESTDIR}/test_parser.c \
		${TESTDIR}/test_token_string.c \
		${TESTDIR}/test_token_null.c \
		${TESTDIR}/test_token_float.c  \
		${TESTDIR}/test_token_integer.c  \
		${TESTDIR}/test_token_bool.c \
		${TESTDIR}/test_parse_json_value.c \
		${TESTDIR}/test_json_free_object.c \
		${TESTDIR}/test_json_free_array.c

OBJ = ${SRC:.c=.o}

TARGET = libjsonparser.a

TARGET_TEST = unit_tests

all: build_all clean

build_all: ${OBJ}
	${AR} ${TARGET} ${OBJ}

tests_run: clean_tests
	${CC} ${CFLAGS} ${CFLAGS_TEST} -o ${TARGET_TEST} ${SRC} ${TEST_FILES} ${LFLAGS} ${LFLAGS_TEST}
	./${TARGET_TEST} --verbose

clean_tests:
	rm -rf ${TARGET_TEST}

coverage: test
	gcovr

clean:
	rm -f ${OBJ} *.gc* unit_test

fclean: clean
	rm -f ${TARGET}

re: fclean all
