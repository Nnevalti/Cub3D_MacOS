NAME	=	libft.a

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strlcat.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_strncat.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strlcpy.c \
			ft_strdup.c \
			ft_strcat.c \
			ft_calloc.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_itoa.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):
			$(CC) $(FLAGS) -c $(SRCS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
