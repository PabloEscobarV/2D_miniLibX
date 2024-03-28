NAME = solong

SRCDIR = src
OBJDIR = obj
MINILIBXDIR = minilibx-linux

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

CC = gcc
CFLAG = -Wall -Wextra -Werror
CMINILIBX = -L$(MINILIBXDIR) -lmlx_Linux -lX11 -lXext

.PHONY: all fclean clean re

all: $(NAME)

clean:
	$(MAKE) -C $(MINILIBXDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MINILIBXDIR)
	$(CC) $(OBJ) -Lminilibx-linux/ -lmlx_Linux -lX11 -lXext -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAG) $< -o $@

