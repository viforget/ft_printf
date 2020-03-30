# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 07:57:46 by viforget          #+#    #+#              #
#    Updated: 2020/02/28 16:42:17 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = @gcc $(CFLAGS)
LIBDIR = libft

SRC = format.c\
	  format2.c\
	  formatp.c\
	  ft_printf.c\
	  setfunction.c\
	  setnumber.c\
	  settxt.c\

O_FILES = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
		@make all -C $(LIBDIR)
		@cp ./libft/libft.a $(NAME)
		@ar rc $(NAME) $(O_FILES)
		@echo "\033[32mCOMPILATION libftprintf.a\033[0m"

clean:
		@rm -rf $(O_FILES)
		@make clean -C $(LIBDIR)
		@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C $(LIBDIR)
		@echo "\033[36mFCLEAN OK\033[0m"

lib:
		@make re -C $(LIBDIR)

norm:
		@norminette $(SRC)

normlib:
		@norminette $(LIBDIR)/*.c

re: fclean all

.PHONY: all fclean clean re lib norm normlib
