# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 20:28:51 by mlinhard          #+#    #+#              #
#    Updated: 2016/01/13 20:29:02 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	gnltest
FLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	main.c

HDIR 	=	./includes/
LDIR 	= 	./libft/
SRCSDIR = 	./srcs/
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

all: $(NAME)

$(NAME):
	make -C $(LDIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft

clean:
	make clean -C $(LDIR)
	/bin/rm -rf $(NAME)

fclean: clean
	make fclean -C $(LDIR)
	/bin/rm -rf $(NAME)

re: fclean all

test: re all
	time ./$(NAME) | /bin/cat -e

leaks: re all -leaks
-leaks:
	valgrind --leak-check=yes --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re test leaks
