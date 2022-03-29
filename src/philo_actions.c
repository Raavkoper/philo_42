/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:56:28 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 17:24:47 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_right(t_philos *philo)
{
	if (philo->id == 1)
		return (philo->data->num_philos - 1);
	else
		return (philo->id - 1);
}

void	eaty_time(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	pthread_mutex_lock(&philo->data->forks[check_right(philo)]);
	printf("This hombre is in eaty time %d\n", philo->id);
	usleep(philo->data->time_to_eat * 10000);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	pthread_mutex_unlock(&philo->data->forks[check_right(philo)]);
}

void	thinky_time(t_philos *philo)
{
	printf("This hombre is in thinky time %d\n", philo->id);
}

void	sleepy_time(t_philos *philo)
{
	printf("This hombre is in sleepy time %d\n", philo->id);
	usleep(philo->data->time_to_sleep * 10000);
}