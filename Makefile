SRCS	= 	srcs/ft_isalpha.c srcs/ft_isdigit.c srcs/ft_isalnum.c srcs/ft_isascii.c srcs/ft_isprint.c srcs/ft_strlen.c srcs/ft_memset.c

INCS	= inc/libft.h

CC		= gcc

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

RM		= rm -f

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME):	$(OBJS)
			ar rc libft.a $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
