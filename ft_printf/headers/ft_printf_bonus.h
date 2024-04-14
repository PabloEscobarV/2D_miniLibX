/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:09:10 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/09 20:57:59 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define SPEC			"scdiufpxX%"
#define MOD				"-0+#. "
#define DEV				'%'
#define FDOT			'.'
#define MINUS			'-'
#define HEX_L			"0123456789ABCDEF"
#define HEX_S			"0123456789abcdef"
#define DEC				"0123456789"
#define BIN				"01"
#define ERROR_BDA		"***BAD MAMMORY ALLOC!***"
#define SIZE_MEM_ADR	16
#define PRE_HEX_S		"0x"
#define PRE_HEX_L		"0X"
#define ZERRO_CH        '0'
#define SPACE_CH        ' '
#define STR_NULL		"(null)"
#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef unsigned int	t_ui;
typedef unsigned long	t_ul;
typedef unsigned char	t_uch;
typedef struct s_mod
{
	t_uch	*flags;
	int		precision;
	int		size;
}			t_mod;
typedef struct s_data
{
	char	*str;
	int		countzerro;
}			t_data;
enum
{
	INDENT,
	ZERO,
	SIGN,
	HEX,
	PREC,
	SPACE,
};
enum
{
	STR,
	CH,
	D_INT,
	I_DAT,
	U_INT,
	F_DAT,
	P_DAT,
	H_D_S,
	H_D_L,
	PRCNT,
};

int			ft_printf(const char *spec, ...);
char		*ft_sprintf(const char *str, ...);
t_data		*lst_tostr(const char *str, va_list arg);
t_list		*str_tolst(const char *str, va_list arg);
void		delt_data(void *ptr);
void		*error_memaloc(t_list *list, void (*del)(void *));
int			printdata(const char *str, va_list arg);
t_data		*prcnttostr(const char *spec);
//////////////////////////////////////STRING//////////////////////////////////
t_data		*t_datacrt(char *str, int countzerro);
t_data		*extren_return(t_data *data, t_mod *mod);
//////////////////////////////////////STRING//////////////////////////////////
t_data		*chartostr(const char ch, const char *spec);
t_data		*tostr_mod(const char *str, const char *spec);
t_data		*ft_strdup_wch(const char *src, char dev);
char		*ft_strcpy_toend(char *dest, const char *src);
char		*emptystr(char ch);
char		*modstr_crt(t_mod *mod, int size, char ch);
t_data		*str_tostr(const char *start, const char *end, const char dev);
t_data		*retres_fin(t_mod *mod, t_data *data, char *s1, char *s2);
//////////////////////////////////////NUMBER//////////////////////////////////
char		*addhexpre(const char *hex, char *str);
int			setsign(t_mod *mod, t_data *num);
t_data		*int_tostr(long n, const char *spec, const char *base);
t_data		*uint_tostr(t_ul n, const char *spec, const char *base);
char		*uint_tostr_base(t_ul n, const char *base);
t_data		*float_tostr(double n, const char *spec, const char *base, t_ui m);
t_data		*hex_tostr(long n, const char *spec, const char *base, char *p_h);
char		*int_tostr_base(long n, const char *base);
char		*crtnumstr(long n, const char *base);
char		*crtnumstr_ul(t_ul n, const char *base);
char		*p_rec(t_ul n, const char *base, char *str, t_ui size);
void		swap(char *s1, char *s2);
void		swap_sign(t_mod *mod, char *str, char *num, char *ch_orig);
t_ui		arrned_num(long n, const char *base);
t_ui		arrned_num_ul(t_ul n, const char *base);
char		*intnum_mod(t_mod *mod, t_data *data, int signe, char ch);
char		*modnstr_crt(t_mod *mod, char *str);
//////////////////////////////////////ADRES////////////////////////////////////
t_data		*addr_tostr(void *p, const char *spec, const char *base);
//////////////////////////////////////FIND SPEC////////////////////////////////
const char	*findstart(const char *spc);
size_t		count_spec(const char *str);
const char	*find_spec(const char *str);
//////////////////////////////////////SET FLAGS////////////////////////////////
t_mod		*setmod(const char *spc, const char *flags, const char *spec_o);
t_mod		*modfree(t_mod *mod);
int			isspec(const char *s, const char *spec_o);