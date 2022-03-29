/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 08:56:39 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 14:00:51 by rkoper        ########   odam.nl         */
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
	int left_fork;
	int id;
}				t_philos;

typedef struct	s_data {
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			times_to_eat;
	t_philos	*philos;
}				t_data;

int		ft_atoi(const char *str);
void	*philo_action(void *philo);
void	create_philos(t_data *data);
void	set_data(t_data *data, char **argv);
void	eaty_time(int id);
void	thinky_time(int id);
void	sleepy_time(int id);
#endif