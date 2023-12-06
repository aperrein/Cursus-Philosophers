# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 09:39:18 by aperrein          #+#    #+#              #
#    Updated: 2023/05/09 09:44:34 by aperrein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

OBJ_DIR =	OBJ/

SRC_DIR =	SRC/

SRC	=	ft_atoi.c init_arg.c main.c routine.c utils.c

OBJ	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM	=	rm -f

CFLAGS	=	-Wall -Werror -Wextra -pthread

all     :       $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		gcc $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
#		@./libft/swaps
		mkdir $(OBJ_DIR)

$(NAME)	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)
		
clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re 	:	fclean $(NAME)
