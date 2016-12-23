# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 00:08:23 by obelange          #+#    #+#              #
#    Updated: 2016/11/12 00:08:25 by obelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

RUN  = a.out

FILES = ft_printf_itoa ft_printf_putstr ft_printf_strdel ft_printf_stric \
ft_printf_strlen ft_printf_strmcat ft_printf_strsub ft_printf_strncpy \
ft_printf_strcat ft_printf_strncat ft_printf_strnew ft_printf_strchri \
ft_printf_strcmp ft_printf_itoa_base ft_printf_strdup ft_printf_itoa_binary \
ft_printf_strcpy ft_printf_fstrappend ft_printf_1chrNsym ft_printf_shiftstr \
ft_printf_Nchr1sym ft_printf_fstrmcat ft_printf_symdet0 ft_printf_chng0 \
ft_printf_chng1 ft_printf_chng2 ft_printf_get0 ft_printf_get1 ft_printf_get2 \
ft_printf_atoi ft_printf_strupper ft_printf_proc_flags

FILES += main

S_PATH = src/
H_PATH = include/
B_PATH = build/

SRC_PRE = $(addprefix $(S_PATH), $(FILES))
SRC = $(addsuffix .c, $(SRC_PRE))

C_OBJ_PRE = $(addprefix $(B_PATH), $(FILES))
C_OBJ = $(addsuffix .o, $(C_OBJ_PRE))

C_FLAGS = -Wall -Werror -Wextra
DEV_FLAGS = $(C_FLAGS) -fsanitize=address

.PHONY : all clean fclean dev re

all : $(NAME)

$(NAME): build $(C_OBJ)
	ar rc $(NAME) $(C_OBJ)

run : fclean build $(C_OBJ)
	gcc $(C_FLAGS) -o $(RUN) $(C_OBJ) && ./$(RUN)

dev : fclean build $(C_OBJ)
	gcc $(DEV_FLAGS) -o $(RUN) $(C_OBJ) && ./$(RUN)

$(B_PATH)%.o: $(S_PATH)%.c	
	gcc -c $< -o $@


build : 
	mkdir build

clean :
	@rm -rf build

fclean : clean
	@rm -f $(NAME) $(RUN)

re : fclean all
