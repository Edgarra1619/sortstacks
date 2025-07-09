NAME1 = push_swap
NAME2 = checker
SRCS1 = pushswap.c parser.c cheapest.c stack.c solve.c
SRCS2 = parser_bonus.c stack_bonus.c checker.c sorted.c
TESTARGS = 10 2 5 12 11 -10 59 -11199 0 200
BONUS = 0
OPTFLAG = 0
SRCDIR = ./srcs/
OBJDIR = ./objs/
LIBFT = ./libft/
CC = cc
INCFLAGS = -I ./includes/ -I $(LIBFT)
CFLAGS = -Wall -Wextra -g -O$(OPTFLAG)
OBJS1 = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS1))
OBJS2 = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS2))

ifeq ($(BONUS), 1)
CFLAGS += -D BONUS
SRCS += 
endif

all: $(NAME1)

bonus: $(NAME2)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME1) $(NAME2)
	$(MAKE) -C $(LIBFT) fclean

re: clean all

$(NAME1): $(OBJS1) $(LIBFT)libft.a
	$(CC) $(CFLAGS) $(OBJS1) $(LIBFT)libft.a -o $@

$(NAME2): $(OBJS2) $(LIBFT)libft.a
	$(CC) $(CFLAGS) $(OBJS2) $(LIBFT)libft.a -o $@

$(OBJS1) $(OBJS2): $(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -c -o $@

$(LIBFT)libft.a:
	make -C $(LIBFT)

$(MINILIBX)libmlx.a $(MINILIBX)libmlx_Linux.a:
	make -C $(MINILIBX)

test: $(NAME1) $(NAME2)
	./$(NAME1) $(TESTARGS) | wc -l
	./$(NAME1) $(TESTARGS) | ./$(NAME2) $(TESTARGS)

gprof: $(NAME)
	./$(NAME) $(TESTARGS)
	rm gprof-output -f
	gprof $(NAME) > gprof-output

valgrind: $(NAME)
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TESTARGS)

gdb: $(NAME)
	gdbtui --args $(NAME) $(TESTARGS)

vgdb: $(NAME)
	valgrind --vgdb=yes --vgdb-error=0 --track-origins=yes ./$(NAME) $(TESTARGS)
