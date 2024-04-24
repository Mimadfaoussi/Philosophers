/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:22:53 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/24 13:42:04 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
* check_input - will check that the input is valid.
* Return : 0 if all good 
*		   1 in case of  error
**/

int	check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (check_syntax(argc, argv) == 1)
		return (1);
	if (ft_atoi(argv[1]) > 200)
		return (1);
	return (0);
}

/**
* check_syntax - will check for syntax error in the input .
* Return : 0 if all good 
*		   1 in case of  error
**/

int	check_syntax(int argc, char **argv)
{
	int	i;
	int	index;

	i = 1;
	while (argv[i])
	{
		index = 0;
		while (argv[i][index])
		{
			if (argv[i][index] < '0' || argv[i][index] > '9')
				return (1);
			index++;
		}
		i++;
	}
	return (0);
}

