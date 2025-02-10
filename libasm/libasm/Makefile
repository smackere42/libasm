NAME = libasm.so

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ = $(SRC:.s=.o)

NASM = nasm
NFLAGS = -felf64 -gdwarf
AR = ar rcs
RM = rm -f
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
TEST = test

all: $(NAME) clean

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(TEST)

test: $(NAME) clean
	$(GCC) $(CFLAGS) main.c $(NAME) -o $(TEST)

re: fclean all test