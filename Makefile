NAME = fdf

LIBFTDIR = libft
GNLDIR = get_next_line
MLXDIR = minilibx-linux
SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
GNL = gnlfull
LIBFT = ft
MLX = mlx_Linux

CC = gcc
CFLAG = -Wall -Wextra -Werror
CLIBFLAFGS = -L$(GNLDIR) -l$(GNL) -L$(LIBFTDIR) -l$(LIBFT) -L$(MLXDIR) -l$(MLX) -lX11 -lXext -lm

.PHONY: all, bonus, clean, fclean, clean_re, re

all: $(NAME)

clean:
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(OBJDIR) $(NAME)

clean_re:
	rm -rf $(OBJDIR) $(NAME)

re: clean_re all

$(NAME): $(OBJ) $(GNL) $(LIBFT) $(MLX)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) -O3 $(CFLAG) $(OBJ) $(CLIBFLAFGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -O3 -c $(CFLAG) $< -o $@

$(GNL):
	$(MAKE) -C $(GNLDIR) bonus

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)



