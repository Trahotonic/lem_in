# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 16:44:06 by rkyslyy           #+#    #+#              #
#    Updated: 2018/01/10 16:44:08 by rkyslyy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

HEADER = ./includes/prlib.h

OPTIONS = -c -I $(HEADER)

SOURCES =	./srcs/convert/ft_allow.c ./srcs/convert/ft_go_zero.c ./srcs/convert/ft_itoa_base.c ./srcs/convert/ft_smoker_atoi.c ./srcs/convert/ft_uitoa_base.c																			\
\
			./srcs/strings/ft_strlen.c ./srcs/strings/ft_putchar.c ./srcs/strings/ft_putstr.c																																			\
\
			./srcs/collect_specs/ft_isdigit.c ./srcs/collect_specs/ft_peace_maker.c ./srcs/collect_specs/ft_get_width.c ./srcs/collect_specs/ft_check_acc.c ./srcs/collect_specs/ft_check_invalid.c ./srcs/collect_specs/ft_collect.c	\
\
			./srcs/make_int/ft_pick_int_type.c ./srcs/make_int/ft_equal_dis_int.c ./srcs/make_int/ft_place_int_left.c ./srcs/make_int/ft_place_int_right.c ./srcs/make_int/ft_print_int.c												\
\
			./srcs/make_hex/ft_pick_hex_type.c ./srcs/make_hex/ft_equal_dis_hex.c ./srcs/make_hex/ft_place_hex_left.c ./srcs/make_hex/ft_place_hex_right.c ./srcs/make_hex/ft_print_hex.c												\
\
			./srcs/make_oct/ft_pick_oct_type.c ./srcs/make_oct/ft_equal_dis_oct.c ./srcs/make_oct/ft_place_oct_left.c ./srcs/make_oct/ft_place_oct_right.c ./srcs/make_oct/ft_print_oct.c												\
\
			./srcs/make_uns/ft_pick_uns_type.c ./srcs/make_uns/ft_equal_dis_uns.c ./srcs/make_uns/ft_place_uns_left.c ./srcs/make_uns/ft_place_uns_right.c ./srcs/make_uns/ft_print_uns.c												\
\
			./srcs/make_adr/ft_equal_dis_adr.c ./srcs/make_adr/ft_place_adr_left.c ./srcs/make_adr/ft_place_adr_right.c ./srcs/make_adr/ft_print_adr.c																					\
\
			./srcs/make_chr/ft_pick_chr_type.c ./srcs/make_chr/ft_equal_dis_chr.c ./srcs/make_chr/ft_place_chr_left.c ./srcs/make_chr/ft_place_chr_right.c ./srcs/make_chr/ft_print_chr.c												\
\
			./srcs/make_str/ft_pick_str_type.c ./srcs/make_str/ft_equal_dis_str.c ./srcs/make_str/ft_place_str_left.c ./srcs/make_str/ft_place_str_right.c ./srcs/make_str/ft_print_str.c ./srcs/make_str/ft_equal_unistr.c ./srcs/make_str/ft_place_uni.c ./srcs/make_str/ft_place_ust_left.c ./srcs/make_str/ft_place_ust_right.c ./srcs/make_str/ft_print_unistr.c \
\
			./srcs/make_per/ft_equal_dis_per.c ./srcs/make_per/ft_place_per_left.c ./srcs/make_per/ft_place_per_right.c ./srcs/make_per/ft_print_per.c																					\
\
			./srcs/unicode/ft_btoi.c ./srcs/unicode/ft_create_mask.c ./srcs/unicode/ft_make_do.c ./srcs/unicode/ft_make_int_array.c ./srcs/unicode/ft_print_uni.c																		\
\
			./srcs/for_print/ft_break.c ./srcs/for_print/ft_check_sc.c ./srcs/for_print/ft_for_inval_wid.c ./srcs/for_print/ft_pick_func.c ./srcs/for_print/ft_put_inval_width.c ./srcs/ft_printf.c

OBJECTS =	./ft_allow.o ./ft_go_zero.o ./ft_itoa_base.o ./ft_smoker_atoi.o ./ft_uitoa_base.o																																\
\
			./ft_strlen.o ./ft_putchar.o ./ft_putstr.o																																										\
\
			./ft_isdigit.o ./ft_peace_maker.o ./ft_get_width.o ./ft_check_acc.o ./ft_check_invalid.o ./ft_collect.o																											\
\
			./ft_pick_int_type.o ./ft_equal_dis_int.o ./ft_place_int_left.o ./ft_place_int_right.o ./ft_print_int.o																											\
\
			./ft_pick_hex_type.o ./ft_equal_dis_hex.o ./ft_place_hex_left.o ./ft_place_hex_right.o ./ft_print_hex.o																											\
\
			./ft_pick_oct_type.o ./ft_equal_dis_oct.o ./ft_place_oct_left.o ./ft_place_oct_right.o ./ft_print_oct.o																											\
\
			./ft_pick_uns_type.o ./ft_equal_dis_uns.o ./ft_place_uns_left.o ./ft_place_uns_right.o ./ft_print_uns.o																											\
\
			./ft_equal_dis_adr.o ./ft_place_adr_left.o ./ft_place_adr_right.o ./ft_print_adr.o																																\
\
			ft_pick_chr_type.o ./ft_equal_dis_chr.o  ./ft_place_chr_left.o ./ft_place_chr_right.o ./ft_print_chr.o																											\
\
			./ft_pick_str_type.o ./ft_equal_dis_str.o ./ft_place_str_left.o ./ft_place_str_right.o ./ft_print_str.o	./ft_equal_unistr.o ./ft_place_uni.o ./ft_place_ust_left.o ./ft_place_ust_right.o ./ft_print_unistr.o	\
\
			./ft_equal_dis_per.o ./ft_place_per_left.o ./ft_place_per_right.o ./ft_print_per.o																																\
\
			./ft_btoi.o ./ft_create_mask.o ./ft_make_do.o ./ft_make_int_array.o ./ft_print_uni.o																															\
\
			./ft_break.o ./ft_check_sc.o ./ft_for_inval_wid.o ./ft_pick_func.o ./ft_put_inval_width.o ./ft_printf.o

all: $(NAME)

$(NAME):
				@ gcc $(FLAGS) $(OPTIONS) $(SOURCES)
				@ ar rc $(NAME) $(OBJECTS)
				@ ranlib $(NAME)

clean:
				@ /bin/rm -f $(OBJECTS)

fclean:	clean
				@ /bin/rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
