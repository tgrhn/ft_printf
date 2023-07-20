SRCS = ft_printf.c ft_printf_utils.c ft_printf_numbers.c

NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $(OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re