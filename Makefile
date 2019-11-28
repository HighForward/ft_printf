
SRCSC		= 	libft/ft_atoi.c\
                libft/ft_putchar.c\
                libft/ft_itoa.c\
				libft/ft_bzero.c\
				libft/ft_isdigit.c\
				libft/ft_strchr.c\
				libft/ft_strlen.c\
				srcs/parsing/ft_printf_args.c\
				srcs/parsing/ft_printf_flags.c\
				srcs/parsing/ft_printf_struct.c\
				srcs/fonctions/ft_printf_hexa.c\
				ft_manage_id.c\
				ft_manage_c.c\
				ft_manage_s.c\
				ft_printf.c\
				ft_printf_manage.c\
				libft/ft_strdup.c
SRCSH		= includes/ft_printf.h
OBJS		= $(SRCSC:%.c=%.o)
NAME		= libftprintf.a
CC			= gcc
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o: ${OBJS}
	@${CC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@echo "\033[1;32m"
			@echo "┌─┐┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐"
			@echo "└─┐│ ││  │  ├┤ └─┐└─┐"
			@echo "└─┘└─┘└─┘└─┘└─┘└─┘└─┘"
			@echo "libftprintf.a generated successfully.\033[0;0m"
			@${AR} ${NAME} ${OBJS} ${SRCSH}

all:		${NAME}

clean:
			@echo "Deleting .o files.."
			@${RM} ${OBJS}

fclean:		clean
			@echo "Deleting binary files.."
			@${RM} ${NAME}

re:			fclean all

test-a:		all
			@${CC} ${NAME} ../testers/main.c -o printf
			@make clean
			@./printf a

test:		all
			${CC} ${NAME} ${LIBFT} ../testers/main.c -o printf
			@make clean
			@./printf

.PHONY:		all clean fclean re