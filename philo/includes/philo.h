/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:03:27 by cben-bar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 14:25:06 by cben-bar         ###   ########lyon.fr   */
=======
/*   Updated: 2022/07/26 18:43:57 by cben-bar         ###   ########.fr       */
>>>>>>> 7fa03f186796a0d39759973afb5a14f9ebf0fd2f
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ****************************************************************************
-----------------------------------INCLUDES-----------------------------------
* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* ****************************************************************************
-------------------------------------ENUM-------------------------------------
* ************************************************************************** */

typedef enum s_bool
{
	false,
	true
}			t_bool;

/* ****************************************************************************
-------------------------------PROTOTYPES STRUCT-------------------------------
* ************************************************************************** */

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	struct s_params		*params;
	struct s_fork		*fork;
	pthread_t			t;
	struct timeval		p_time;
	long				last_meal;
	int					name;
	long				kaputt;
	int					must_eat;
	struct s_philo		*next;
}				t_philo;

typedef struct s_params
{
	struct s_philo	*first;
	int				nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_each_philo_must_eat;
	long				start_time;
	pthread_mutex_t	really_eat;
	int				nb_really_eat;
	pthread_mutex_t	death;
	int				dead;
}				t_params;

/* ****************************************************************************
------------------------------PROTOTYPES PARSING------------------------------
* ************************************************************************** */

int			main(int ac, char **av);
t_bool		parsing(int ac, char **av);
int			ft_atoi(char *str);

/* ****************************************************************************
--------------------------------PROTOTYPES INIT--------------------------------
* ************************************************************************** */

t_params	*init_params(int ac, char **av);
t_philo		*init_nb_philo(t_params *ptr_params);
t_philo		*init_philo(t_params *ptr_params, int i);
t_bool		ft_go(t_philo *ptr_philo);

/* ****************************************************************************
-------------------------------PROTOTYPES UTILS-------------------------------
* ************************************************************************** */

void		ft_lstadd_back(t_philo **alst, t_philo *new);
void		cleaner(t_philo *ptr_philo);
long		ft_time(t_philo *philo);
t_bool		kaputt(t_philo *philo);
t_bool		ft_thinking(int name, t_philo *philo);
t_bool		ft_eating(t_philo *philo);
t_bool		ft_sleeping(int name, t_philo *philo);
t_bool		rest_meal(t_philo *philo);
void		ft_usleep(t_philo *philo, long wait);
void		check_alive(t_philo *philo);

#endif
