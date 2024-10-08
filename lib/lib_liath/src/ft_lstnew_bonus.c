/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:30:01 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:37 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstnew
Prototype 			t_list *ft_lstnew(void *content);
Turn in files 		-
Parameters 			content: The content to create the node with.
Return value 		The new node
External functs. 	malloc
Description 		Allocates (with malloc(3)) and returns a new node.
					The member variable ’content’ is initialized with
					the value of the parameter ’content’. The variable
					’next’ is initialized to NULL.
*/

#include "../../../inc/lib_liath.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
