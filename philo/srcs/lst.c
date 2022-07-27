/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:26:43 by cben-bar          #+#    #+#             */
/*   Updated: 2022/07/12 18:27:49 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleaner(t_philo *ptr_philo)
{
	t_philo	*tmp;
	int		i;

	i = 1;
	if (ptr_philo)
	{
		while (i != ptr_philo->params->nb_philo)
		{
			tmp = ptr_philo;
			free(tmp->fork);
			ptr_philo = ptr_philo->next;
			free(tmp);
			tmp = NULL;
			i++;
		}
		free(ptr_philo->fork);
		free(ptr_philo);
		ptr_philo = NULL;
	}
}

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*tmp;

	if (!(alst) || !new)
		return ;
	tmp = ft_lstlast(*alst);
	if (!tmp)
		*alst = new;
	else
		tmp->next = new;
}
