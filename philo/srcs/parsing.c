/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:39:21 by cben-bar          #+#    #+#             */
/*   Updated: 2022/07/25 21:16:50 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool	check_args(char *av)
{
	size_t	i;

	i = 0;
	while (av[i] == ' ')
		i++;
	while (av[i] >= '0' && av[i] <= '9')
		i++;
	while (av[i] == ' ')
		i++;
	if (av[i] == '\0')
		return (true);
	printf("ERROR: Expected arguments can only be positive numbers\n");
	return (false);
}

t_bool	check_nb_args(char ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("ERROR: Arguments are missing\n");
		return (false);
	}
	return (true);
}

t_bool	complete_arg(char *av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ' || av[i] == '\0')
		{
			printf("ERROR: Empty argument\n");
			return (false);
		}
		i++;
	}
	return (true);
}

t_bool	parsing(int ac, char **av)
{
	size_t	i;

	i = 1;
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			return (false);
	}
	if (!check_nb_args(ac))
		return (false);
	if (ft_atoi(av[1]) < 1)
	{
		printf("ERROR: At least one philosopher is needed\n");
		return (false);
	}
	while (av[i])
	{
		if (!complete_arg(av[i]))
			return (false);
		if (!check_args(av[i]))
			return (false);
		i++;
	}
	return (true);
}
