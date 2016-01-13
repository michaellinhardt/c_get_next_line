# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 03:40:52 by mlinhard          #+#    #+#              #
#    Updated: 2016/01/13 16:40:48 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= libft.a
LIST_SRC		= \
	ft_strlen.c		ft_strcmp.c		ft_strdup.c		ft_strcpy.c		ft_strncpy.c \
	ft_strcat.c		ft_strncat.c	ft_strlcat.c	ft_strchr.c		ft_strrchr.c \
	ft_strstr.c		ft_strnstr.c	ft_strncmp.c	ft_putendl.c	ft_itoa.c \
	ft_putchar.c	ft_putchar_fd.c	ft_putstr.c		ft_putstr_fd.c	ft_strrev.c \
	ft_putnbr_fd.c	ft_putnbr.c		ft_stralloc.c	ft_putendl_fd.c	ft_pow.c \
	ft_islower.c	ft_isupper.c	ft_toupper.c	ft_tolower.c	ft_countwords.c \
	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_lstmap.c \
	ft_isprint.c	ft_isspace.c	ft_strdel.c		ft_strclr.c		ft_striter.c \
	ft_striteri.c	ft_strmap.c		ft_strmapi.c	ft_strequ.c		ft_strnequ.c \
	ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c	ft_memmove.c \
	ft_memchr.c		ft_memcmp.c		ft_memalloc.c	ft_memdel.c		ft_strnew.c \
	ft_atoi.c		ft_strsub.c		ft_strjoin.c	ft_strtrim.c	ft_strsplit.c \
	ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		ft_lstiter.c \
	ft_pcol.c		ft_arrcpy.c		ft_arrlen.c		ft_arrfree.c	ft_arrprint.c \
	ft_strtolower.c	ft_strtoupper.c
LIST_OBJ		= $(subst .c,.o,$(LIST_SRC))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./ -c -o $@ $<

$(NAME): $(LIST_OBJ)
	ar rc $(NAME) $(LIST_OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(LIST_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re clear
