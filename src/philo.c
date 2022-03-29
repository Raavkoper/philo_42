/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:59:57 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 15:00:30 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_action(void *philosopher)
{
	t_philos *philo;
	pthread_mutex_t lock;
	
	philo = (t_philos *)philosopher;
	pthread_mutex_init(&lock, NULL);
	while (1)
	{
		pthread_mutex_lock(&lock);
		eaty_time(philo->id);
		pthread_mutex_unlock(&lock);
		thinky_time(philo->id);
		sleepy_time(philo->id);
	}
}

void	create_philos(t_data *data)
{
	int i;

	i = 1;
	while (i < data->num_philos)
	{
		data->philos[i].id = i;
		data->philos[i].left_fork = i;
		pthread_create(&data->philos[i].thread, NULL, philo_action, &data->philos[i]);
		i++;
		sleep(1);
	}
}

void	set_data(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[1]) + 1;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->times_to_eat = ft_atoi(argv[4]);
	data->philos = malloc(sizeof(t_philos) * data->num_philos);
}

int main(int argc, char **argv)
{
	t_data data;

	set_data(&data, argv);
	create_philos(&data);
	while (1);
}
