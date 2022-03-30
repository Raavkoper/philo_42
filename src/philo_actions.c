/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:56:28 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/30 14:58:06 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_right(t_philos *philo)
{
	if (philo->id == 1)
		return (philo->data->num_philos - 1);
	else
		return (philo->id - 2);
}

void	eaty_time(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_lock(&philo->data->forks[check_right(philo)]);
	print_action(philo, 'e');
	philo->meal = time_stamp() - philo->data->start;
	if (philo->meal - philo->prev_meal > philo->data->time_to_die)
		print_action(philo, 'd');
	philo->prev_meal = philo->meal;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[check_right(philo)]);
}

void	thinky_time(t_philos *philo)
{
	print_action(philo, 't');
}

void	sleepy_time(t_philos *philo)
{
	print_action(philo, 's');
	usleep(philo->data->time_to_sleep * 1000);
}

long	time_stamp(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_action(t_philos *philo, char c)
{
	if (c == 'd')
	{
		printf("%ld   %sHombre %d tried to swim in lava💀❌%s\n" \
		,time_stamp() - philo->data->start, RED, philo->id, NC);
		exit (0);
	}
	else if (c == 'e')
		printf("%ld   %sHombre %d is in eaty time🍕🍻%s\n" \
		,time_stamp() - philo->data->start, RED, philo->id, NC);
	else if (c == 's')
		printf("%ld   %sHombre %d is in sleepy time🛌🧸%s\n" \
		,time_stamp() - philo->data->start, BLUE, philo->id, NC);
	else if (c == 't')
		printf("%ld   %sHombre %d is in thinky time💭💰%s\n" \
		,time_stamp() - philo->data->start, YELLOW, philo->id, NC);
}