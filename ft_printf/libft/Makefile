# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 18:21:04 by polenyc           #+#    #+#              #
#    Updated: 2024/02/29 09:58:02 by blackrider       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BONUSNAME = libftfull.a

SRC = $(wildcard *.c)
SRCBONUS = $(wildcard *.c)

OBJ_DIR = objs
OBJDIRBONUS = $(OBJ_DIR)/objsbonus
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
OBJECTSBONUS = $(addprefix $(OBJ_DIR)/, $(SRCBONUS:%.c=%.o))
CC = gcc
CFLAGSO = -c -Wall -Wextra -Werror
.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(BONUSNAME)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME) $(BONUSNAME)

re: fclean all

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(BONUSNAME): $(OBJECTSBONUS)
	ar rc $(BONUSNAME) $(OBJECTSBONUS)
	ranlib $(BONUSNAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGSO) $< -o $@

# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGSO) $< -o $@

# SRC = ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c \
# ft_putnbr_fd.c ft_putnbr.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c \
# ft_putstr_fd.c ft_putstr.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcmp.c \
# ft_split.c ft_strmapi.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
# ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c ft_memset.c \
# ft_striteri.c ft_strrchr.c ft_isprint.c ft_putchar_fd.c ft_putchar.c \
# ft_strjoin.c ft_strtrim.c ft_strcmp.c ft_atoi_base.c ft_isspace.c \
# ft_strjoinfree.c ft_strcpy.c \

# SRCBONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
# ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
# ft_lstnew_bonus.c ft_lstsize_bonus.c \