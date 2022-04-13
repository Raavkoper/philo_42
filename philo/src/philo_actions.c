/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:56:28 by rkoper        #+#    #+#                 */
/*   Updated: 2022/04/13 13:58:21 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eaty_time(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->forks[check_right(philo)]);
	print_action(philo, 'f', check_right(philo));
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	print_action(philo, 'f', philo->id - 1);
	pthread_mutex_lock(&philo->data->eating);
	philo->meal = time_stamp();
	print_action(philo, 'e', 0);
	philo->meals_left--;
	pthread_mutex_unlock(&philo->data->eating);
	ft_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&philo->data->forks[check_right(philo)]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
}

void	print_action(t_philos *philo, char c, int fork)
{
	pthread_mutex_lock(&philo->data->writing);
	if (!philo->data->died)
	{	
		if (c == 'f')
			printf("%ld   %sHombre %d picked up fork %d🥄🥢%s\n",
				time_stamp() - philo->data->start, GREEN, philo->id, fork, NC);
		else if (c == 'e')
			printf("%ld   %sHombre %d is eating🍕🍻%s\n",
				time_stamp() - philo->data->start, RED, philo->id, NC);
		else if (c == 's')
			printf("%ld   %sHombre %d is sleepy🛌%s\n",
				time_stamp() - philo->data->start, BLUE, philo->id, NC);
		else if (c == 't')
			printf("%ld   %sHombre %d is thinking💭💰%s\n",
				time_stamp() - philo->data->start, YELLOW, philo->id, NC);
	}
	pthread_mutex_unlock(&philo->data->writing);
}

void	ft_sleep(long time, t_data *data)
{
	long	i;

	i = time_stamp();
	while (!data->died)
	{
		if ((time_stamp() - i) >= time)
			break ;
		usleep(25);
	}
}

void	finish_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	free(data->philos);
	free(data->forks);
}
