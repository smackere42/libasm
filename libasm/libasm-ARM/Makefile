NAME = libasm_test
CC = clang
CFLAGS = -Wall -Wextra

SRCS = main.c
ASM_SRCS = ft_strlen.s ft_strcpy.s ft_strdup.s ft_strcmp.s ft_write.s ft_read.s
OBJS = $(SRCS:.c=.o) $(ASM_SRCS:.s=.o)
OUTS = ft_read_output ft_write_output linux_read_output linux_write_output

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c libasm.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all