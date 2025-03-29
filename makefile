# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:03:58 by lkiloul           #+#    #+#              #
#    Updated: 2025/03/29 13:40:51 by lkiloul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
INCLUDES = -I libft/includes -I.
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT = client
SERVER = server
LIBFT = libft/libft.a

all: $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C libft

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) -L libft -lft

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) -L libft -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re