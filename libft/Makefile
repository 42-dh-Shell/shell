NAME = libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRCS = ft_atoi.c ft_bzero.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c \
ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_itoa.c  \
ft_memchr.c  ft_memcmp.c \
ft_memcpy.c  ft_memmove.c  ft_memset.c  ft_putchar_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_exit.c \
ft_free_split.c ft_strcmp.c 

BONUSES=  ft_lstnew.c ft_lstadd_back.c  ft_lstadd_front.c  ft_lstclear.c  ft_lstclear.c  ft_lstdelone.c \
ft_lstiter.c  ft_lstlast.c  ft_lstmap.c  ft_lstsize.c 

OBJS = ${SRCS:.c=.o}
BONUS_OBJS= ${BONUSES:.c=.o}
ifdef WITH_BONUS
OBJ_FILES = ${OBJS} ${BONUS_OBJS}
else
OBJ_FILES = ${OBJS}
endif

all:	${NAME}

${NAME}: ${OBJ_FILES}
		${AR} $@ ${OBJ_FILES}
bonus:
	WITH_BONUS=1 make all
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
clean:
	${RM} ${OBJS} ${BONUS_OBJS}
fclean:		clean
			${RM} ${NAME}
re:
	${MAKE} fclean
	${MAKE} all

.PHONY:  all clean fclean re bonus
