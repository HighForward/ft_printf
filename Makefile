NAME		=	a.out

SRCS		=	ft_printf.c \
                libft.a     \
                ft_printf_struct.c \
                ft_printf_utils.c   \
                ft_printf_args.c    \
                ft_printf_manage.c    \
                ft_printf_flag_hypen.c \
                ft_printf_flag_zero.c   \
                ft_printf_flag_point.c  \
                ft_printf_no_flag.c     \

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
