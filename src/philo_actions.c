/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:56:28 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/31 14:00:26 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eaty_time(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	print_action(philo, 'f', philo->id - 1);
	pthread_mutex_lock(&philo->data->forks[check_right(philo)]);
	print_action(philo, 'f', check_right(philo));
	philo->meal = time_stamp() - philo->data->start;
	print_action(philo, 'e', 0);
	philo->data->times_to_eat--;
	philo->prev_meal = philo->meal;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[check_right(philo)]);
}

void	print_action(t_philos *philo, char c, int fork)
{
	pthread_mutex_lock(&philo->data->right);	
	if (c == 'd' && check(philo))
	{
		printf("%ld   %sHombre %d tried to swim in lava💀❌%s\n" \
		,time_stamp() - philo->data->start, RED, philo->id, NC);
	}
	else if (c == 'f' && !check(philo))
		printf("%ld   %sHombre %d picked up fork %d🥄🥢%s\n" \
		,time_stamp() - philo->data->start, GREEN, philo->id, fork, NC);
	else if (c == 'e' && !check(philo))
		printf("%ld   %sHombre %d is in eaty time🍕🍻%s\n" \
		,time_stamp() - philo->data->start, RED, philo->id, NC);
	else if (c == 's' && !check(philo))
		printf("%ld   %sHombre %d is in sleepy time🛌🧸%s\n" \
		,time_stamp() - philo->data->start, BLUE, philo->id, NC);
	else if (c == 't' && !check(philo))
		printf("%ld   %sHombre %d is in thinky time💭💰%s\n" \
		,time_stamp() - philo->data->start, YELLOW, philo->id, NC);
	pthread_mutex_unlock(&philo->data->right);
}