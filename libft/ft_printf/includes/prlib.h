/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:05:49 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:05:50 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRLIB_H
# define PRLIB_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_specs
{
	int		plus;
	int		leftside;
	int		width;
	int		zero;
	int		count;
	int		accuracy;
	int		space;
	int		digit_flag;
	int		acc_flag;
	int		hash;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		z;
	int		j;
	wchar_t c;
	wchar_t	*str;
	int		permis;
	int		flag;
}				t_specs;

typedef struct	s_pozor
{
	char				*array;
	char				tmp[60];
	char				*ret;
	int					size;
	int					ptr;
	int					minus;
	unsigned long long	backup;
}				t_pozor;

int				ft_break(va_list ptr, int ret);
int				ft_isdigit(int c);
char			*ft_itoa(long long n);
char			*ft_allow(char *str);
size_t			ft_strlen(char const *str);
char			*ft_go_zero(void);
char			*ft_itoa_base(long long value, int base);
char			*ft_uitoa_base(unsigned long long value, int base);
int				ft_btoi(char *bin);
char			**ft_create_mask(int size);
char			**ft_make_do(char *bin, char **arr, int pointer);
int				*ft_make_int_array(char **list, int size);
void			ft_print_uni(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_smoker_atoi(const char *nptr);
t_specs			ft_peace_maker(void);
char			*ft_get_width(char *format, t_specs *specs);
char			*ft_check_acc(char *format, t_specs *specs, va_list ptr);
int				ft_check_invalid(char *format);
char			*ft_collect(char *format, t_specs *specs, va_list ptr);
void			ft_equal_dis_uns(t_specs *specs, unsigned long long n);
int				ft_pick_uns_type(t_specs specs, va_list ptr, char u);
int				ft_place_uns_left(unsigned long long n, t_specs specs);
int				ft_place_uns_right(unsigned long long n, t_specs specs);
int				ft_print_uns(unsigned long long n, t_specs specs);
int				ft_pick_int_type(t_specs specs, va_list ptr, char d);
int				ft_pick_oct_type(t_specs specs, va_list ptr, char o);
int				ft_pick_hex_type(t_specs specs, va_list ptr, char x);
void			ft_equal_dis_int(t_specs *specs, long long n);
int				ft_place_int_left(long long n, t_specs specs);
int				ft_place_int_right(long long n, t_specs specs);
int				ft_print_int(long long n, t_specs specs);
void			ft_equal_dis_hex(t_specs *specs, unsigned long long n);
int				ft_place_hex_left(unsigned long long n, t_specs specs, char x);
int				ft_place_hex_right(unsigned long long n, t_specs specs, char x);
int				ft_print_hex(unsigned long long n, t_specs specs, char x);
void			ft_equal_dis_oct(t_specs *specs, unsigned long long n);
int				ft_place_oct_left(unsigned long long n, t_specs specs);
int				ft_place_oct_right(unsigned long long n, t_specs specs);
int				ft_print_oct(unsigned long long n, t_specs specs);
void			ft_equal_dis_adr(t_specs *specs, unsigned long long n);
int				ft_place_adr_left(unsigned long long n, t_specs specs);
int				ft_place_adr_right(unsigned long long n, t_specs specs);
int				ft_print_adr(unsigned long long n, t_specs specs);
void			ft_equal_dis_chr(t_specs *specs, unsigned int c);
int				ft_pick_chr_type(t_specs specs, va_list ptr, char c);
int				ft_place_chr_left(unsigned int c, t_specs specs, char uni);
int				ft_place_chr_right(unsigned int c, t_specs specs, char uni);
int				ft_print_chr(unsigned int c, t_specs specs, char uni);
void			ft_equal_dis_str(t_specs *specs, char *str);
int				ft_pick_str_type(t_specs specs, va_list ptr, char s);
void			ft_equal_unistr(t_specs *specs, wchar_t *str);
void			ft_place_uni(wchar_t *str);
int				ft_place_ust_left(wchar_t *str, t_specs specs);
int				ft_place_ust_right(wchar_t *str, t_specs specs);
int				ft_print_unistr(wchar_t *str, t_specs specs);
int				ft_place_str_left(char *str, t_specs specs);
int				ft_place_str_right(char *str, t_specs specs);
int				ft_print_str(char *str, t_specs specs);
void			ft_equal_dis_per(t_specs *specs);
int				ft_place_per_left(t_specs specs);
int				ft_place_per_right(t_specs specs);
int				ft_print_per(t_specs specs);
int				ft_check_sc(char *format, t_specs *specs, va_list ptr);
int				ft_for_inval_wid(char *format, t_specs specs, int ret);
int				ft_pick_func(char c, t_specs specs, va_list ptr);
void			ft_put_inval_width(int width, int zero);
int				ft_printf(char *format, ...);

#endif
