NAME= mzaboub.filler

SRC_PATH= src
SRC_NAME= parser.c resolve.c draw_heatmap.c fortest_funcs.c

HDR_PATH= headers
HDR_NAME= filler.h

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB_PATH= libftprintf
LIB= libftprintf.a

# **************************************************************************** #

CC=	gcc
CFLAGES= -Wall -Wextra -Werror

LD_FLAGS= -L$(LIB_PATH)
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))

HDR_FLAGS= -I headers

# **************************************************************************** #

all:$(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@ echo "\033[1;32m>> Filler binary is ready ;)\n\033[0m"
	@$(CC) $(LD_FLAGS) $(LD_LIBS) $(CFLAGS) $(OBJ) -o $@

$(LIB_PATH)/$(LIB):
	@make -C $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libftprintf clean
	@echo "\033[1;33m>> filler object files deleted.\n\033[0m" 

fclean: clean
	@rm -fr $(NAME)
	@make -C libftprintf fclean
	@echo "\033[0;31m>> filler all resources deleted.\n\033[0m" 

re: fclean all
