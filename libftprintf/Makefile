# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 06:06:14 by mzaboub           #+#    #+#              #
#    Updated: 2020/01/01 12:26:26 by mzaboub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC_PATH= src
SRC_NAME=	ft_atoi.c  		ft_bzero.c		ft_charinword.c	ft_isalnum.c	\
		 	ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprime.c 	\
		 	ft_isprint.c 	ft_itoa.c 		ft_lstadd.c  	ft_lstdel.c		\
		 	ft_lstiter.c	ft_lstmap.c		ft_lstnew.c		ft_lstsize.c 	\
		 	ft_lstsplit.c	ft_memalloc.c	ft_memccpy.c	ft_memchr.c 	\
		 	ft_memcmp.c		ft_memcpy.c		ft_memcpynull.c	ft_memdel.c 	\
		 	ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c \
		 	ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	\
		 	ft_putstr.c		ft_putstr_fd.c	ft_sqrt.c		ft_strcat.c		\
		 	ft_strchr.c		ft_strclr.c		ft_strcmp.c		ft_strcpy.c		\
		 	ft_strdel.c		ft_strdup.c		ft_strequ.c		ft_striter.c	\
		 	ft_striteri.c	ft_strjoin.c	ft_strlcat.c	ft_strlen.c		\
		 	ft_strmap.c		ft_strmapi.c	ft_strncat.c	ft_strncmp.c 	\
		 	ft_strncpy.c	ft_strnequ.c	ft_strnew.c		ft_strnstr_origin.c \
		 	ft_strrchr.c	ft_strrev.c		ft_strsplit.c	ft_strstr.c 	\
		 	ft_strsub.c		ft_strtrim.c	ft_tolower.c	ft_toupper.c 	\
		 	get_next_line.c	ft_lstdelone.c 	ft_isupper.c \
		 	apply_signs.c					fetch_by_sizem.c \
			apply_hash.c					apply_width.c \
			ft_putonbr.c					save_precision.c \
			ft_printf.c						ft_putunbr.c \
			save_width.c					apply_precision.c \
			build_result.c					ft_putxnbr.c \
			apply_quote.c					ft_putdnbr.c \
			save_flags.c					main_original.c \
			ft_putfnbr.c 					ft_putc_and_s.c \
			set_color.c						ft_putxstr.c \
			float_bigint_add_sub_comp.c		float_all_bigint_functions.c \
			float_bigint_initial_tools.c	float_construction_functions.c \
			float_bigint_add_sub_comp.c		float_helper_functions_unnecessary.c \
			float_bigint_initial_tools.c	float_main_functions.c \
			float_bigint_shift_functs.c		float_mini_dragon4.c \
			float_scientific_construction.c	float_mini_dragon4_2.c 

HDR_PATH=	headers
HDR_NAME= 	libft.h ft_printf.h float_bigint.h

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/, $(HDR_NAME))

# **************************************************************************** #

CFLAGS=  -Wall -Wextra -Werror
CC= gcc
HDR_FLAGS= -I headers

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32m ->> libftprintf: library compilled.\n\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[0;35m ->> libft: object files deleted.\n\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m ->> libft: library deleted.\n\033[0m"

re: fclean all
