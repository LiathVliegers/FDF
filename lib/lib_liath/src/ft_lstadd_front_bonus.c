/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:28:52 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:22 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstadd_front
Prototype 			void ft_lstadd_front(t_list **lst, t_list *new);
Turn in files 		-
Parameters 			lst:	The address of a pointer to the first link of a list.
					new:	The address of a pointer to the node to be 
							added to the list.
Return value 		None
External functs. 	None
Description 		Adds the node ’new’ at the beginning of the list.
*/

#include "../../../inc/lib_liath.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*new_node;

	if (lst == NULL || new == NULL)
		return ;
	new_node = new;
	if (new_node == NULL)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}
