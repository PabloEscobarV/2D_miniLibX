/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:45:12 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/13 20:10:37 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

t_mod	*modfree(t_mod *mod)
{
	free(mod->flags);
	free(mod);
	return (NULL);
}

t_mod	*modcrt(const char *flags)
{
	t_mod	*mod;
	t_ui	size;

	mod = malloc(sizeof(t_mod));
	if (!mod)
		return (NULL);
	size = ft_strlen(flags);
	mod->flags = ft_calloc((size + 1), sizeof(t_ui));
	if (!mod->flags)
		return (modfree(mod));
	mod->precision = 0;
	mod->size = 0;
	return (mod);
}

t_ui	setflags(const char *spc, const char *flags, t_mod *mod)
{
	int	i;

	i = 0;
	while (*spc != flags[i] && flags[i])
		++i;
	if (*spc != flags[i])
		return (0);
	mod->flags[i] = *spc;
	return (1);
}

t_mod	*setnmod(const char *spc, const char *flags, const char *m, t_mod *mod)
{
	if (!ft_isdigit(*spc))
		return (NULL);
	if (*(spc - 1) == flags[PREC])
	{
		mod->precision = ft_atoi(spc);
		return (mod);
	}
	mod->size = ft_atoi(spc);
	spc += arrned_num(mod->size, DEC);
	if (isspec(spc, m))
		return (mod);
	if (*spc != flags[PREC])
		return (modfree(mod));
	mod->flags[PREC] = flags[PREC];
	mod->precision = ft_atoi(spc + 1);
	return (mod);
}

t_mod	*setmod(const char *spc, const char *flags, const char *spec_o)
{
	t_mod		*mod;
	const char	*tmp_spec;

	mod = modcrt(flags);
	if (!mod)
		return (NULL);
	tmp_spec = findstart(spc);
	while (setflags(tmp_spec, flags, mod))
		++tmp_spec;
	if (tmp_spec == spc)
		return (mod);
	return (setnmod(tmp_spec, flags, spec_o, mod));
}
