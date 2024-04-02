/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_charstring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:22:29 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:54 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/lib_liath.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *str)
{
	int	len;

	if (str == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

