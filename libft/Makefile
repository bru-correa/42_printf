# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 17:37:06 by bcorrea-          #+#    #+#              #
#    Updated: 2021/09/28 20:45:00 by bcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Werror -Wextra -ansi
CC		= gcc
INCLUDE	= libft.h
TEST_SH	= tests/start_tests.sh

MAIN_S	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
MAIN_O	= $(MAIN_S:.c=.o)
BONUS_S	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
BONUS_O	= $(BONUS_S:.c=.o)

# REMOVE LATER
# TEST_S	= $(addprefix ./tests/src/tests/, $(MAIN_S))
TEST_B	= $(basename $(addprefix ./tests/bin/, $(MAIN_O)))

all: $(NAME)

$(NAME): $(MAIN_O) $(INCLUDE)
	ar -rcs $(NAME) $(MAIN_O)

%.o: %.c
	$(CC) $(FLAGS) -c -I ./ $< -o $@

bonus: $(NAME) $(BONUS_O)
	ar -rcs $(NAME) $(BONUS_O)

clean:
	rm -f $(MAIN_O) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus test cleanlogs cleanbin

# REMOVE LATER
test: all cleanlogs $(TEST_B) #insert bonus here later
	$(TEST_SH)

./tests/bin/%: ./tests/src/tests/%.c
	$(CC) $(FLAGS) $< ./tests/lib/libtest.a $(NAME) \
		-I ./tests/include -I ./ -o $@

libtest.a:
	$(CC) $(FLAGS) ./tests/src/tests.c -I ./tests/include -o ./tests/obj/tests.o
	ar -rcs $@ ./tests/obj/tests.o

cleanlogs:
	find ./tests/logs -type f -name "*.log" | xargs -n 1 rm -f

cleanbin:
	find ./tests/bin -type f | xargs -n 1 rm -f

test2: all
	../Libfttest/grademe.sh

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(MAIN_S) $(BONUS_S)
	$(CC) -nostartfiles -shared -o libft.so $(MAIN_O) $(BONUS_O)
