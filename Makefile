# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mforest- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 08:57:42 by mforest-          #+#    #+#              #
#    Updated: 2024/10/12 01:00:03 by mforest-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
TEST = test_libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_calloc.c ft_strnstr.c ft_memset.c ft_strlcat.c ft_bzero.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_split.c ft_itoa.c ft_substr.c ft_strmapi.c ft_strtrim.c ft_striteri.c
OBJS = $(SRCS:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

so: $(OBJS)
	$(CC) $(OBJS) --shared -o libft.so

run: main.c $(NAME)
	$(CC)  main.c $(NAME) -Wall -Wextra -o a.out
	./a.out

run2: main.c $(NAME)
	$(CC)  main.c $(NAME) -Wall -Wextra -o a.out
	valgrind ./a.out

run3: all
	./libft_tester/libft_tester

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re run run2 run3 so
