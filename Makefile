SOURCES := $(wildcard src/*.s)

HEADERS := $(wildcard src/*.h)

OBJECTS := $(patsubst src/%.s,objs/%.o,$(SOURCES))

NAME := libasm.a

AS := nasm
AR := ar

ASFLAGS := -f elf64
ARFLAGS := rcs

objs/%.o: src/%.s
	$(AS) $(ASFLAGS) $< -o $@

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(HEADERS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(OBJECTS): objs

objs:
	mkdir -p objs

.PHONY: all clean fclean re bonus
