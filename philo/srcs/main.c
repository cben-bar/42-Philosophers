/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:04:10 by cben-bar          #+#    #+#             */
/*   Updated: 2022/07/25 20:04:01 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_params	*ptr_params;
	t_philo		*ptr_philo;

	if (parsing(ac, av))
	{
		ptr_params = init_params(ac, av);
		if (!ptr_params)
			return (0);
		ptr_philo = init_nb_philo(ptr_params);
		if (!ft_go(ptr_philo))
		{
			cleaner(ptr_philo);
			return (0);
		}
		pthread_mutex_destroy(&ptr_philo->fork->mutex);
		cleaner(ptr_philo);
		free(ptr_params);
	}
	return (0);
}
