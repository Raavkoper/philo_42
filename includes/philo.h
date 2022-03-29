/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 08:56:39 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 17:24:19 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct	s_philos {
	pthread_t thread;
	int fork;
	int id;
	struct s_data *data;
}				t_philos;

typedef struct	s_data {
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_to_eat;
	t_philos	*philos;
	pthread_mutex_t *forks;
}				t_data;


int		ft_atoi(const char *str);
void	*philo_action(void *philo);
void	create_philos(t_data *data);
void	set_data(t_data *data, char **argv);
void	eaty_time(t_philos *philo);
void	thinky_time(t_philos *philo);
void	sleepy_time(t_philos *philo);
int		check_right(t_philos *philo);
#endif