NAME = fdf
LIB = libft.a
MKDIR = obj
SRC = $(wildcard src/*.c)
LIBS = -L./libft/ -lft  -L -lmlx -framework OPENGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

OBJ_PATH = ./obj/
SRC_PATH = ./src/
INC_PATH = ./includes/

INCLUDES = -I$(INC_PATH)

OBJ = $(patsubst src/%.c,$(OBJ_PATH)%.o,$(SRC))


all: $(MKDIR) $(LIB) $(NAME)

$(MKDIR):
	@mkdir $(MKDIR)
$(LIB):
	@(cd libft && $(MAKE))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc  $(CFLAGS) $(INCLUDES) -o $@ -c $^

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBS)

clean:
	@(cd libft && $(MAKE) $@)
	@/bin/rm -f $(OBJ)

fclean: clean
	@(cd libft && $(MAKE) $@)
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all