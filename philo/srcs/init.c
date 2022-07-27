/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:08:09 by cben-bar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 14:25:27 by cben-bar         ###   ########lyon.fr   */
=======
/*   Updated: 2022/07/26 18:43:31 by cben-bar         ###   ########.fr       */
>>>>>>> 7fa03f186796a0d39759973afb5a14f9ebf0fd2f
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_params	*init_params(int ac, char **av)
{
	t_params	*ptr_params;

	ptr_params = malloc(sizeof(t_params));
	if (!ptr_params)
		return (NULL);
	ptr_params->nb_philo = ft_atoi(av[1]);
	ptr_params->time_to_die = ft_atoi(av[2]);
	ptr_params->time_to_eat = ft_atoi(av[3]);
	ptr_params->time_to_sleep = ft_atoi(av[4]);
	ptr_params->dead = 0;
	ptr_params->start_time = 0;
	ptr_params->nb_really_eat = 0;
	if (ac == 6)
		ptr_params->nb_each_philo_must_eat = ft_atoi(av[5]);
	else
		ptr_params->nb_each_philo_must_eat = -1;
	if (ptr_params->nb_each_philo_must_eat == 0)
		return (NULL);
	return (ptr_params);
}

t_philo	*init_philo(t_params *params, int i)
{
	t_philo	*ptr_philo;
	t_fork	*fork;

	ptr_philo = malloc(sizeof(t_philo));
	if (!ptr_philo)
		return (NULL);
	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	ptr_philo->params = params;
	ptr_philo->fork = fork;
	ptr_philo->last_meal = 0;
	ptr_philo->name = i + 1;
	ptr_philo->kaputt = 0;
	if (params->nb_each_philo_must_eat)
		ptr_philo->must_eat = 0;
	else
		ptr_philo->must_eat = -1;
	ptr_philo->next = NULL;
	return (ptr_philo);
}

t_philo	*init_nb_philo(t_params *ptr_params)
{
	t_philo	*new;
	t_philo	*ptr_philo;
	int		i;

	i = 0;
	while (i != ptr_params->nb_philo)
	{
		new = init_philo(ptr_params, i);
		if (i == 0)
		{
			ptr_philo = new;
			ptr_philo->params->first = new;
		}
		else
		{
			ptr_philo->next = new;
		}
		ptr_philo = new;
		i++;
	}
	new->next = ptr_philo->params->first;
	return (ptr_philo);
}
