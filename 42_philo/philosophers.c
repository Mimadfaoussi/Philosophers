/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:19:29 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/24 13:42:28 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (check_input(argc, argv) == 1)
	{
		printf("Input Error\n");
		return (1);
	}
	printf("all good we can keep on \n");
	return (0);
}
