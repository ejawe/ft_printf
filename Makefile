# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 11:05:21 by dmontgen          #+#    #+#              #
#    Updated: 2020/02/10 12:37:24 by dmontgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

NAME	= libftprintf.a

SRC_PATH = ./src
LIBFT_PATH = ./src/libft
INCLUDE_PATH = ./include
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME = ft_printf.c\
				conversion_s/ft_string_s.c\
				conversion_s/ft_field_width_s.c\
				conversion_s/ft_get_precision_s.c\
				conversion_s/ft_print_zero_n_space_s.c\
				conversion_s/ft_ret_s.c\
				conversion/ft_string_d.c\
				conversion/ft_flag.c\
				conversion/ft_stock_field_width.c\
				conversion/ft_until_no_digit.c\
				conversion/ft_precision.c\
				conversion/ft_string_width.c\
				conversion/ft_print_zero_precision.c\
				conversion/ft_convert_arg.c\
				conversion/ft_print_zero_n_space.c\
				conversion/ft_print_left_space.c\
				conversion/ft_ret.c\

LIBFT_NAME = ft_strlen.c\
				ft_isdigit.c\
				ft_strnstr.c\
				ft_my_atoi.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strnew.c\
				ft_itoa.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_my_putnbr_fd.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_putnbr_base.c\
				ft_my_count_base.c\

INCLUDE_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIBFT_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIBFT = $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))
INCLUDE = $(addprefix $(INCLUDE_PATH)/, $(INCLUDE_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/, $(OBJLIB_NAME))

all: $(NAME)

$(NAME) : $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj
	@mkdir -p obj/conversion
	@mkdir -p obj/conversion_s
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIBFT_PATH)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	@rm -rf ./obj $(NAME)

re: fclean all
