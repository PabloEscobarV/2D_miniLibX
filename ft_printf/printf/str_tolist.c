/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tolist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:28:20 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/20 13:27:06 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

void	*error_memaloc(t_list *list, void (*del)(void *))
{
	ft_lstclear(&list, del);
	return (NULL);
}

t_data	*write_chrs(const char *spec, va_list arg)
{
	if (*spec == SPEC[PRCNT])
		return (prcnttostr(spec));
	if (*spec == SPEC[CH])
		return (chartostr(va_arg(arg, int), spec));
	if (*spec == SPEC[STR])
		return (tostr_mod(va_arg(arg, char *), spec));
	if (*spec == SPEC[P_DAT])
		return (addr_tostr(va_arg(arg, void *), spec, HEX_S));
	return (NULL);
}

t_data	*write_digit(const char *spec, va_list arg)
{
	if (*spec == SPEC[D_INT])
		return (int_tostr(va_arg(arg, int), spec, DEC));
	if (*spec == SPEC[I_DAT])
		return (int_tostr(va_arg(arg, int), spec, DEC));
	if (*spec == SPEC[U_INT])
		return (uint_tostr(va_arg(arg, t_ui), spec, DEC));
	if (*spec == SPEC[F_DAT])
		return (float_tostr(va_arg(arg, double), spec, DEC, 6));
	if (*spec == SPEC[H_D_S])
		return (hex_tostr(va_arg(arg, t_ui), spec, HEX_S, PRE_HEX_S));
	if (*spec == SPEC[H_D_L])
		return (hex_tostr(va_arg(arg, t_ui), spec, HEX_L, PRE_HEX_L));
	return (NULL);
}

t_data	*write_data(const char *spec, va_list arg)
{
	t_data	*tmp;

	tmp = write_chrs(spec, arg);
	if (tmp)
		return (tmp);
	return (write_digit(spec, arg));
}

t_list	*str_tolst(const char *str, va_list arg)
{
	t_list		*list;
	t_list		*lst_tmp;
	const char	*spec;
	t_data		*s_tmp;

	list = ft_lstnew(NULL);
	lst_tmp = list;
	spec = find_spec(str);
	while (spec)
	{
		list->content = str_tostr(str, spec, DEV);
		s_tmp = write_data(spec, arg);
		if (!s_tmp)
			return (error_memaloc(list, &delt_data));
		list->next = ft_lstnew(s_tmp);
		list->next->next = ft_lstnew(NULL);
		list = list->next->next;
		str = spec + 1;
		spec = find_spec(str);
	}
	list->content = ft_strdup_wch(str, DEV);
	return (lst_tmp);
}
