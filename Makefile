# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 20:28:51 by mlinhard          #+#    #+#              #
#    Updated: 2016/01/22 08:07:52 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	gnltest
FLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	main.c \
			get_next_line.c

HDIR 	=	./includes/
LDIR 	= 	./libft/
SRCSDIR = 	./srcs/
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

RE			= \033[0;31m
GR			= \033[0;32m
YE			= \033[0;33m
BL			= \033[0;34m
WH			= \033[0;38m
OK			= $(WH)* [ $(GR)OK $(WH)]
KO			= $(WH)* [ $(RE)KO $(WH)]
W8			= $(WH)* [ $(BL)W8 $(WH)]

all: $(NAME)

$(NAME):
	@echo "$(W8) $(YE)make -C $(LDIR)$(WH)"
	@make -C $(LDIR)
	@echo "$(W8) $(YE)gcc $(FLAGS) (SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft$(WH)"
	@gcc $(FLAGS) $(SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft
	@echo "$(OK) $(GR)Done!$(WH)"

clean:
	@echo "$(W8) $(YE)make clean -C $(LDIR)$(WH)"
	@make clean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf $(NAME)$(WH)"
	@/bin/rm -rf $(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

fclean: clean
	@echo "$(W8) $(YE)make fclean -C $(LDIR)$(WH)"
	@make fclean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf ./last.valgrind$(WH)"
	@/bin/rm -rf ./last.valgrind
	@echo "$(W8) $(YE)/bin/rm -rf ./gnltest.dSYM$(WH)"
	@/bin/rm -rf ./gnltest.dSYM
	@echo "$(OK) $(GR)Done!$(WH)"

re: fclean all

test: re
	@echo "$(W8) $(YE)time ./$(NAME) | /bin/cat -e$(WH)"
	@time ./$(NAME) | /bin/cat -e
	@echo "$(OK) $(GR)Done!$(WH)"

leaks: re -leaks
-leaks:
	@echo "$(W8) $(YE)valgrind --leak-check=yes --track-origins=yes ./$(NAME) > ./last.valgrind 2>&1$(WH)"
	@valgrind --leak-check=yes --track-origins=yes ./$(NAME) > ./last.valgrind 2>&1
	@echo "$(W8) $(YE)/bin/cat -e ./last.valgrind$(WH)"
	@/bin/cat -e ./last.valgrind
	@echo "$(OK) $(GR)Done!$(WH)"

.PHONY: all clean fclean re test leaks
