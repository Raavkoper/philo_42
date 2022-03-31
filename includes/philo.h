/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 08:56:39 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/31 13:59:46 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

# define NC "\x1B[0m"
# define BLUE "\033[0;34m"
# define RED "\x1B[31m"
# define YELLOW "\x1B[33m"
# define GREEN "\033[1m\033[32m"

typedef struct	s_philos {
	pthread_t thread;
	int 		id;
	long 		meal;
	long		prev_meal;
	struct s_data *data;
}				t_philos;

typedef struct	s_data {
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_to_eat;
	long		start;
	int			state;
	t_philos	*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t	is_dead;
	pthread_mutex_t right;
}				t_data;


int		ft_atoi(const char *str);
void	*philo_action(void *philo);
void	create_philos(t_data *data);
void	set_data(t_data *data, char **argv);
void	eaty_time(t_philos *philo);
int		check_right(t_philos *philo);
void	print_action(t_philos *philo, char c, int fork);
long	time_stamp(void);
int		check_dead(t_data *data);
int		check(t_philos *philo);
#endif