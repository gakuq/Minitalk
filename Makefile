# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 14:43:07 by mmaterna          #+#    #+#              #
#    Updated: 2025/04/01 14:41:29 by mmaterna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

CLIENT	= client
SERVER	= server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

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

$(SERVER_BONUS):	$(SERVER_BONUS).c minitalk.h $(LIBFT) $(PRINTF)
			@echo "$(BLUE)Compiling the server_bonus.$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS).c $(LIBFT) $(PRINTF)
			@echo "$(GREEN)[OK]$(CLEAR)"

$(CLIENT_BONUS):	$(CLIENT_BONUS).c minitalk.h $(LIBFT) $(PRINTF)
			@echo "$(PINK)Compiling the client_bonus.$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS).c $(LIBFT) $(PRINTF)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"
$(LIBFT):
	make -C $(LIBFT_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

$(NAME):	$(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

bonus:		$(SERVER_BONUS) $(CLIENT_BONUS)

clean:
			@echo "$(BLUE)Make clean/fclean$(CLEAR)\n$(RED)Removing all compiled files.$(CLEAR)"
			@$(RM) $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)
			@echo "$(GREEN)Success!$(CLEAR)\n$(YELLOW)Finished$(CLEAR)\n"

fclean:		clean

re:			fclean all
