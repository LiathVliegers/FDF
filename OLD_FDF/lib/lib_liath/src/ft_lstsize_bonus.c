/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:30:07 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:40 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstsize
Prototype 			int ft_lstsize(t_list *lst);
Turn in files 		-
Parameters 			lst: The beginning of the list.
Return value 		The length of the list
External functs. 	None
Description 		Counts the number of nodes in a list.
*/

#include "../../../inc/lib_liath.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
// CHANGE HEAD BACK TO lst!!!!!!!!!!!!!!!
// int	ft_lstsize(t_list *lst)
// {
// 	int		count;

// 	// if (head == NULL)
// 	// 	return ;
// 	count = 0;
// 	// size = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		count++;
// 	}
// 	return (count);
// }