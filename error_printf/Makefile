NAME = errorprintf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRCS = apply_all.c \
eval_all.c \
ft_isflag.c \
ft_printf.c \
handle_sign.c \
num_hexlen.c \
pack_clear.c \
print_addr.c \
print_char.c \
print_decimal.c \
print_lowerhex.c \
print_str.c \
print_unsigned.c \
print_upperhex.c \
ul_to_hexp.c \
unitprint.c \
update.c \
util_len.c \
print_iszero.c

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
		${AR} $@ ${OBJS}
		
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
clean:
	${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:
	${MAKE} fclean
	${MAKE} all

.PHONY:  all clean fclean re bonus
