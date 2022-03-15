# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 13:51:00 by mac               #+#    #+#              #
#    Updated: 2022/03/15 03:56:33 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	*.c

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=thread

NAME			= philo
				
all:			$(NAME)

$(NAME):		$(SRCS)
				gcc  $(FLAGS) $(SRCS) -o $(NAME)
				
clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)