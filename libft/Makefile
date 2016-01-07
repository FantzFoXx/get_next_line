# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 17:09:04 by udelorme          #+#    #+#              #
#    Updated: 2016/01/07 10:41:54 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
BIN = exec
INCREP = includes/
OBJREP = obj/
FLAGS = -Wall -Werror -Wextra
SRC =	ft_isalpha.c  	\
		ft_memccpy.c  	\
		ft_memmove.c  	\
		ft_strcat.c   	\
		ft_strdel.c   	\
		ft_strjoin.c  	\
		ft_strncat.c  	\
		ft_strnstr.c  	\
		ft_strtrim.c  	\
		ft_isascii.c  	\
		ft_memchr.c   	\
		ft_memset.c   	\
		ft_strchr.c   	\
		ft_strdup.c		\
		ft_strlcat.c	\
		ft_strncmp.c 	\
		ft_strrchr.c 	\
		ft_tolower.c	\
		ft_atoi.c 		\
		ft_isdigit.c 	\
		ft_memcmp.c  	\
		ft_putchar.c	\
		ft_strclr.c  	\
		ft_strequ.c 	\
		ft_strlen.c 	\
		ft_strncpy.c 	\
		ft_strsplit.c 	\
		ft_toupper.c	\
		ft_bzero.c  	\
		ft_isprint.c	\
		ft_memcpy.c  	\
		ft_putnbr.c  	\
		ft_strcmp.c  	\
		ft_striter.c  	\
		ft_strmap.c 	\
		ft_strnequ.c 	\
		ft_strstr.c 	\
		ft_wordcount.c	\
		ft_isalnum.c 	\
		ft_memalloc.c 	\
		ft_memdel.c 	\
		ft_putstr.c  	\
		ft_trace.c  	\
		ft_nbrtrace.c  	\
		ft_strcpy.c 	\
		ft_striteri.c	\
		ft_strmapi.c 	\
		ft_strnew.c  	\
		ft_strsub.c		\
		ft_putendl.c	\
		ft_itoa.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c		\
		ft_lstadd.c		\
		ft_lstpush.c	\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_lstdup.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SRC) -I $(INCREP)
	ar rc $(NAME) $(OBJ)
	mv $(OBJ) $(OBJREP)

clean :
	rm -rf $(OBJREP)
	mkdir $(OBJREP)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BIN)

re : fclean all
