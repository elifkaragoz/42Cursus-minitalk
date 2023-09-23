SERVER_SRCS = server.c 
CLIENT_SRCS = client.c
FT_PRINTF = ft_printf/libftprintf.a

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: server client

server: $(SERVER_OBJS) $(FT_PRINTF)
	gcc $(FLAGS) -o server $(SERVER_OBJS) $(FT_PRINTF)

client: $(CLIENT_OBJS) $(FT_PRINTF)
	gcc $(FLAGS) -o client $(CLIENT_OBJS) $(FT_PRINTF)

$(FT_PRINTF):
	make -C ft_printf

clean:
	rm -rf *.o
	make -C ft_printf clean

fclean: clean
	rm -rf server
	rm -rf client
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
