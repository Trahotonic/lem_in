# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 14:50:42 by rkyslyy           #+#    #+#              #
#    Updated: 2017/11/14 17:30:35 by rkyslyy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -c -Wall -Wextra -Werror

HEADER = libft.h

SOURCES = ./ft_atoi.c ./ft_bzero.c ./ft_ch.c ./ft_filler.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c \
			./ft_isprint.c ./ft_itoa.c ./ft_lstadd.c ./ft_lstdel.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstnew.c  \
			./ft_memalloc.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memdel.c ./ft_memmove.c ./ft_memset.c \
			./ft_putchar.c ./ft_putchar_fd.c ./ft_putendl.c ./ft_putendl_fd.c ./ft_putnbr.c ./ft_putnbr_fd.c ./ft_putstr.c \
			./ft_putstr_fd.c  ./ft_size.c ./ft_strcat.c ./ft_strchr.c ./ft_strclr.c ./ft_strcmp.c ./ft_strcpy.c \
			./ft_strdel.c ./ft_strdup.c ./ft_strequ.c ./ft_striter.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlen.c \
			./ft_strmap.c ./ft_strmapi.c ./ft_strncat.c ./ft_strncmp.c ./ft_strncpy.c ./ft_strnequ.c ./ft_strnew.c ./ft_strnstr.c \
			./ft_strrchr.c ./ft_strsplit.c ./ft_strstr.c ./ft_strsub.c ./ft_strtrim.c ./ft_tolower.c ./ft_toupper.c ./ft_wc.c \
			./ft_wl.c ./get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ make -C ./ft_printf
	@ ar	rc	$(NAME)	$(OBJECTS) ./ft_printf/*.o
	@ ranlib $(NAME)

%.o: %.c $(HEADER)
	@ gcc	$(FLAGS)	-o	$@ $<

clean:
	 @ /bin/rm	-f	$(OBJECTS)
	 @ make clean -C ./ft_printf

fclean: clean
	 @ make fclean -C ./ft_printf
	 @ /bin/rm	-f	$(NAME)

re:	fclean all

