NAME	= libftprintf.a

SRCS	=	ft_nb.c\
			ft_string.c\
			ft_printf.c

OBJS	=	ft_nb.o\
			ft_string.o\
			ft_printf.o
		
FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

bonus:
	cc $(FLAGS) -c $(SRCS_B)
	ar rc $(NAME) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all
