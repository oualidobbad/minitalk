FLAGS = -Wall -Wextra -Werror
SRC_CLT = client.c ft_atoi.c ft_putstr.c
SRC_SRV = server.c ft_putnbr_fd.c ft_putstr.c
OBJ_CLT = $(SRC_CLT:.c=.o)
OBJ_SRV = $(SRC_SRV:.c=.o)
NAME_CLT = client
NAME_SRV = server 

all: $(NAME_CLT) $(NAME_SRV)

$(NAME_CLT): $(OBJ_CLT)
	cc -o $@ $(SRC_CLT)

$(NAME_SRV): $(OBJ_SRV)
	cc -o $@ $(SRC_SRV) 
clean:
	rm -rf $(OBJ_CLT) $(OBJ_SRV)
fclean: clean
	rm -rf $(NAME_CLT) $(NAME_SRV)
re: fclean all