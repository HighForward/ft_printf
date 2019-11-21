NAME		=	a.out

SRCS		=	ft_printf.c \
                libft.a

OBJS		=	${SRCS:.c=.o}

FLAGS		=	-Wall -Wextra -Werror -g3 -Iincludes

CC			=	gcc

RM			=	rm -f

.c.o:
				$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
				ar rcs $(NAME) ${OBJS}

all: $(NAME)

clean:
				${RM} ${OBJS}

fclean: clean
				${RM} $(NAME)

re:	fclean all

.PHONY: all clean fclean re
