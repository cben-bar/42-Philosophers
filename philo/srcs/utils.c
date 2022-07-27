/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:19:55 by cben-bar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 14:26:29 by cben-bar         ###   ########lyon.fr   */
=======
/*   Updated: 2022/07/26 18:44:51 by cben-bar         ###   ########.fr       */
>>>>>>> 7fa03f186796a0d39759973afb5a14f9ebf0fd2f
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_alive(t_philo *philo)
{
	while (philo)
	{
		if (kaputt(philo))
			break ;
		philo = philo->next;
	}
}

void	set_dead(t_philo *philo)
{
	philo->params->dead = 1;
	philo->kaputt = ft_time(philo);
}

t_bool	kaputt(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->death);
	if (philo->params->dead)
	{
		pthread_mutex_unlock(&philo->params->death);
		return (true);
	}
	pthread_mutex_lock(&philo->params->really_eat);
//	if (philo->params->nb_really_eat == philo->params->nb_philo)
//	{
//		pthread_mutex_unlock(&philo->params->death);
//		pthread_mutex_unlock(&philo->params->really_eat);
//		return (true);
//	}
	pthread_mutex_unlock(&philo->params->really_eat);
	if (ft_time(philo) - philo->last_meal >= philo->params->time_to_die)
	{
		if (philo->params->dead == 0)
			set_dead(philo);
		pthread_mutex_unlock(&philo->params->death);
		return (true);
	}
	pthread_mutex_unlock(&philo->params->death);
	return (false);
}

t_bool	rest_meal(t_philo *philo)
{
	if (philo->must_eat != philo->params->nb_each_philo_must_eat)
		return (true);
	return (false);
}

void	ft_usleep(t_philo *philo, long wait)
{
	long	time;

	time = ft_time(philo);
	while (ft_time(philo) - time < wait)
	{
		if (philo->params->nb_philo > 100)
			usleep(1000);
		else
			usleep(100);
	}
}

long	ft_time(t_philo *philo)
{
	long	mili;

	gettimeofday(&philo->p_time, NULL);
	mili = philo->p_time.tv_sec * 1000;
	mili += philo->p_time.tv_usec / 1000;
	return (mili - philo->params->start_time);
}
