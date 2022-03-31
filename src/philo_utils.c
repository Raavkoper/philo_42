/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 16:10:19 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/31 13:59:05 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	outcome;

	outcome = 0;
	min = 1;
	i = 0;
	if (!str)
		return (-1);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			min *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		outcome = (outcome * 10) + (*str - '0');
		str++;
		i++;
	}
	return (outcome * min);
}

long	time_stamp(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	check_right(t_philos *philo)
{
	if (philo->id == 1)
		return (philo->data->num_philos - 1);
	else
		return (philo->id - 2);
}

void	confirm_death(t_data *data)
{
	pthread_mutex_lock(&data->is_dead);
	data->state++;
	pthread_mutex_unlock(&data->is_dead);
}

int	check(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->is_dead);
	if (philo->data->state)
	{
		pthread_mutex_unlock(&philo->data->is_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead);
	return (0);
}

int	check_dead(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{	
		if (data->philos[i].meal - data->philos[i].prev_meal > data->time_to_die)
		{
			confirm_death(data);
			print_action(&data->philos[i], 'd', 0);
			return (1);
		}
		i++;
	}
	return (0);
}