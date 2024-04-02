/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:28:41 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:19 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstadd_back
Prototype 			void ft_lstadd_back(t_list **lst, t_list *new);
Turn in files 		-
Parameters 			lst: The address of a pointer to the first link of a list.
					new: The address of a pointer to the node to be 
					added to the list.
Return value 		None
External functs. 	None
Description 		Adds the node ’new’ at the end of the list.
*/

#include "../../../inc/lib_liath.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_node;
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	new_node = new;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		return ;
	}
}
