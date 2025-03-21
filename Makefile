# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 14:43:07 by mmaterna          #+#    #+#              #
#    Updated: 2025/03/20 18:31:21 by mmaterna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

CLIENT	= client
SERVER	= server

RED		=	\033[91;1m]
GREEN	=	\033[92;1m]
YELLOW	=	\033[93;1m]
BLUE	=	\033[94;1m]
PINK	=	\033[95;1m]
CLEAR	=	\033[0m]

LIBFT_PATH      =   ./Libft
LIBFT           =   $(LIBFT_PATH)/libft.a

PRINTF_PATH		=	./Printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

all:		$(NAME)

$(SERVER):	$(SERVER).c minitalk.h $(LIBFT) $(PRINTF)
			@echo "$(BLUE)Make all$(CLEAR)\n$(PINK)Compiling the server.$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).c $(LIBFT) $(PRINTF)
			@echo "$(GREEN)[OK]$(CLEAR)"

$(CLIENT):	$(CLIENT).c minitalk.h $(LIBFT) $(PRINTF)
			@echo "$(PINK)Compiling the Client.$(CLEAR)\n$(GREEN)[OK]$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).c $(LIBFT) $(PRINTF)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

$(NAME):	$(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

clean:
			@echo "$(BLUE)Make clean/fclean$(CLEAR)\n$(RED)Removing all compiled files.$(CLEAR)"
			@$(RM) $(CLIENT) $(SERVER)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

fclean:		clean

re:			fclean all
