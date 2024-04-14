/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:11:48 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/04 16:01:52 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// static int	ft_isalpha(int arg)
// {
// 	unsigned char	ch;

// 	ch = (unsigned char)arg;
// 	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
// }

// static int	ft_isupper(int arg)
// {
// 	unsigned char	ch;

// 	ch = (unsigned char)arg;
// 	if (ch >= 'A' && ch <= 'Z')
// 		return (1);
// 	return (0);
// }

// int	ft_toupper(int ch)
// {
// 	if (!ft_isalpha(ch))
// 		return (ch);
// 	if (ft_isupper(ch))
// 		return (ch);
// 	return (ch - 32);
// }

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}
