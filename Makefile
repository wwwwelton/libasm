SOURCES_FILES = main.c
SOURCES_DIR = ./

OBJ_DIR = objects

HEADERS =

SOURCES = $(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS = $(SOURCES: $(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = Libasm

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADERS)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJECTS) $(HEADERS)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
