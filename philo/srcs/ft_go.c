/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:56:15 by cben-bar          #+#    #+#             */
/*   Updated: 2022/07/27 14:26:00 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philo)
{
	t_philo	*ptr_philo;

	ptr_philo = philo;
	while (1)
	{
		if (!ft_thinking(ptr_philo->name, ptr_philo))
			break ;
		if (ptr_philo->name % 2 == 0)
		{
			if (!ft_sleeping(ptr_philo->name, ptr_philo))
				break ;
		}
		if (!ft_eating(ptr_philo))
			break ;
		if (ptr_philo->name % 2 != 0)
		{
			if (!ft_sleeping(ptr_philo->name, ptr_philo))
				break ;
		}
		if (ptr_philo->must_eat == ptr_philo->params->nb_each_philo_must_eat)
			break ;
	}
	if (ptr_philo->kaputt)
		printf("\e[1;31m%ld %d died\n\e[0m", ptr_philo->kaputt, ptr_philo->name);
	return (NULL);
}

t_bool	jointh(t_philo *ptr_philo)
{
	int	i;

	i = 0;
	while (i != ptr_philo->params->nb_philo)
	{
		if (pthread_join(ptr_philo->t, NULL) != 0)
		{
			printf("ERROR: pthread_join\n");
			return (false);
		}
		ptr_philo = ptr_philo->next;
		i++;
	}
	ptr_philo = ptr_philo->params->first;
	return (true);
}

t_bool	createth(t_philo *ptr_philo)
{
	int	i;

	i = 0;
	ptr_philo->params->start_time = ft_time(ptr_philo);
	while (i != ptr_philo->params->nb_philo)
	{
		if (pthread_create(&ptr_philo->t, NULL, \
				&routine, (void *)ptr_philo) != 0)
		{
			printf("ERROR: pthread_create\n");
			return (false);
		}
		ptr_philo = ptr_philo->next;
		i++;
	}
	ptr_philo = ptr_philo->params->first;
	return (true);
}

t_bool	init_mutex(t_philo *ptr_philo)
{
	int	i;

	i = 0;
	while (i != ptr_philo->params->nb_philo)
	{
		if (pthread_mutex_init(&ptr_philo->fork->mutex, NULL) != 0)
		{
			printf("ERROR: pthread mutex init\n");
			return (false);
		}
		ptr_philo = ptr_philo->next;
		i++;
	}
	ptr_philo = ptr_philo->params->first;
	return (true);
}

t_bool	ft_go(t_philo *ptr_philo)
{
	if (!init_mutex(ptr_philo))
		return (false);
	if (!createth(ptr_philo))
		return (false);
	check_alive(ptr_philo);
	if (!jointh(ptr_philo))
		return (false);
	return (true);
}
