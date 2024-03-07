/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:36:48 by livliege          #+#    #+#             */
/*   Updated: 2024/03/07 21:53:32 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
	TODO's:
	
	PARSE COLOURS
	CLOSE ALL FD'S IN A BETTER WAY 				// in function parse_file
*/


// 1: ERROR: Incorrect number of arguments
// 2: ERROR: Memory allocation failed
// 3: ERROR: Invalid fd
// 4: ERROR: Invalid map file
// 5: ERROR: Empty map
// 6: ERROR: Lines in file are not consistent


void	ft_exit(int error_code)
{
	char* error_message;
	
	if (error_code == 1)
		error_message = "ERROR: Incorrect number of arguments\n";
	else if (error_code == 2)
		error_message = "ERROR: Memory allocation failed\n";
	else if (error_code == 3)
		error_message = "ERROR: Invalid fd\n";
	else if (error_code == 4)
		error_message = "ERROR: Invalid map file\n";
	else if (error_code == 5)
		error_message = "ERROR: Empty map\n";
	else if (error_code == 6)
		error_message = "ERROR: Lines in file are not consistent\n";
	else
		error_message = "ERROR: Unknown error\n";
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(1);
}

// VINCENTS TIPS:

// void	exit_error(t_data *data, char *msg)
// {
// 	clean_up(data);
// 	ft_putendl_fd(msg, STDERR_FILENO);
// 	exit(EXIT_FAILURE);
// }


// void	*ft_malloc(t_data *data, size_t size)
// {
// 	void	*thingy;

// 	thingy = malloc(size);
// 	if (thingy == NULL)
// 		exit_error(data, "malloc failed");
// 	return (thingy);
// }