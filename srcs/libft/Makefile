# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mscot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 21:10:56 by mscot             #+#    #+#              #
#    Updated: 2021/02/07 10:05:23 by mscot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

SRC		=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strnstr.c	\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_isspace.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	

BNS		=	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

OBJ			=	$(SRC:.c=.o) $(BNS:.c=.o)

CC			=	gcc 

.PHONY: 	all clean fclean re bonus

all:		$(NAME)

%.o:		%.c libft.h
			$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME):	$(OBJ)
			ar ruv $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all


