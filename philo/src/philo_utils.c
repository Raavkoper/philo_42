/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 16:10:19 by rkoper        #+#    #+#                 */
/*   Updated: 2022/04/13 20:54:19 by rkoper        ########   odam.nl         */
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
	if (*str != '\0')
		return (-1);
	return (outcome * min);
}

long	time_stamp(void)
{
	struct timeval	tv;

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

int	check_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_left)
			return (0);
		i++;
	}
	return (1);
}

void	check_dead(t_data *data)
{
	int	i;

	i = 0;
	while (!data->died)
	{	
		pthread_mutex_lock(&data->eating);
		if (time_stamp() - data->philos[i].meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->writing);
			data->died += 1;
			printf("%ld   %sHombre %d tried to swim in lava💀❌%s\n",
				time_stamp() - data->start, RED, data->philos[i].id, NC);
			pthread_mutex_unlock(&data->writing);
		}
		if (check_full(data))
		{
			pthread_mutex_unlock(&data->eating);
			return ;
		}
		pthread_mutex_unlock(&data->eating);
		i++;
		i %= data->num_philos;
	}
}
