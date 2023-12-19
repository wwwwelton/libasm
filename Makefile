SOURCES := $(wildcard src/*.s)

HEADERS := $(wildcard src/*.h)

OBJECTS := $(patsubst src/%.s,objs/%.o,$(SOURCES))

TEST := $(wildcard test/*.c) main.c

TEST_NAME := test.out

NAME := libasm.a

AS := nasm
AR := ar
CC := gcc

ASFLAGS := -f elf64
ARFLAGS := rcs
CFLAGS := -Wall -Wextra -Werror -g

objs/%.o: src/%.s
	$(AS) $(ASFLAGS) $< -o $@

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(HEADERS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -rf objs output.txt stdout.txt input1.txt input2.txt

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

re: fclean all

$(OBJECTS): objs

objs:
	mkdir -p objs

test: $(NAME)
	@$(CC) $(CFLAGS) $(TEST) $(NAME) -o $(TEST_NAME)
	@./$(TEST_NAME) ft_read

.PHONY: all clean fclean re bonus test
