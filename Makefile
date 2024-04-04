NAME = fdf

SRCDIR = src
OBJDIR = obj
MINILIBXDIR = minilibx-linux

# SRC = $(wildcard $(SRCDIR)/*.c)
SRC = src/fdf.c
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

CC = gcc
CFLAG = -Wall -Wextra
CMINILIBX = -L$(MINILIBXDIR) -lmlx_Linux -lX11 -lXext

.PHONY: all fclean clean re

all: $(NAME)

clean:
	$(MAKE) -C $(MINILIBXDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

clean_only:
	rm -rf $(OBJDIR) $(NAME)

re: clean_only $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MINILIBXDIR)
	$(CC) $(OBJ) -Lminilibx-linux/ -lmlx_Linux -lX11 -lXext -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAG) $< -o $@

