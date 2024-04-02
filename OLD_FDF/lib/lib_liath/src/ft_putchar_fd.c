/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:03:56 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:07:07 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_putchar_fd
Prototype 			void ft_putchar_fd(char c, int fd);
Turn in files 		-
Parameters 			c: The character to output.
					fd: The file descriptor on which to write.
Return value 		None
External functs. 	write
Description 		Outputs the character ’c’ to the given file descriptor.
*/

#include "../../../inc/lib_liath.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
