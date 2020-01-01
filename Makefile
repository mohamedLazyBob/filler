NAME= filler

SRC_PATH= src
SRC_NAME=	parsser.c

HDR_PATH= headers
HDR_NAME= filler.h

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB_OBJ_PATH= libftprintf/obj/*.o

LIB_PATH= libftprintf
LIB= libftprintf.a

# **************************************************************************** #

CC=	gcc
CFLAGES= -Wall -Wextra -Werror

LD_FLAGS= -L$(LIB_PATH)
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))

HDR_FLAGS= -I.

# **************************************************************************** #

all:$(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	$(cc) $(CFLAGES) -o $(NAME) $(OBJ) $(LIB_OBJ_PATH)
	@ranlib $(NAME)
	@ echo "\033[1;32m>> ft_printf: library file is ready ;)\n\033[0m"

$(LIB_PATH)/$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@echo "\033[1;33m>> ft_printf: object files deleted.\n\033[0m" 

fclean: clean
	@rm -fr $(NAME)
	@make -C libft fclean
	@echo "\033[0;31m>> ft_printf: all resources deleted.\n\033[0m" 

re: fclean all
