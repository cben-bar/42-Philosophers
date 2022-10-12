/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:33:18 by cben-bar          #+#    #+#             */
/*   Updated: 2022/10/12 17:34:26 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	first_fork(t_philo *philo)
{
	if (kaputt(philo))
		return (false);
	while (1)
	{
		if (pthread_mutex_lock(&philo->fork->mutex) == 0)
			break ;
	}
	return (true);
}

int	twice_fork(t_philo *philo)
{
	if (kaputt(philo))
		return (false);
	while (1)
	{
		if (pthread_mutex_lock(&philo->next->fork->mutex) == 0)
			break ;
	}
	pthread_mutex_lock(&philo->params->death);
	if (philo->params->dead == 0)
	{
		printf("\e[1;30m%ld %d has taken a fork\n\e[0m", \
		ft_time(philo), philo->name);
		printf("\e[1;30m%ld %d has taken a fork\n\e[0m", \
		ft_time(philo), philo->name);
	}
	pthread_mutex_unlock(&philo->params->death);
	return (true);
}

t_bool	ft_sleeping(int name, t_philo *philo)
{
	if (kaputt(philo))
		return (false);
	printf("\e[1;34m%ld %d is sleeping\e[0m\n", ft_time(philo), name);
	ft_usleep(philo, philo->params->time_to_sleep);
	return (true);
}

t_bool	ft_eating(t_philo *philo)
{
	if (!first_fork(philo))
		return (false);
	if (!twice_fork(philo))
		return (false);
	if (kaputt(philo))
		return (false);
	philo->last_meal = ft_time(philo);
	printf("\e[1;38m%ld %d is eating\n\e[0m", \
	philo->last_meal, philo->name);
	ft_usleep(philo, philo->params->time_to_eat);
	pthread_mutex_unlock(&philo->fork->mutex);
	pthread_mutex_unlock(&philo->next->fork->mutex);
	philo->must_eat++;
	if (philo->must_eat == philo->params->nb_each_philo_must_eat)
	{
		pthread_mutex_lock(&philo->params->really_eat);
		philo->params->nb_really_eat++;
		pthread_mutex_unlock(&philo->params->really_eat);
	}
	return (true);
}

t_bool	ft_thinking(int name, t_philo *philo)
{
	if (kaputt(philo))
		return (false);
	printf("\e[1;36m%ld %d is thinking\e[0m\n", ft_time(philo), name);
	if (philo->params->nb_philo == 1)
		ft_usleep(philo, philo->params->time_to_die + 1);
	return (true);
}
