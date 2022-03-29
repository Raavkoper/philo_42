/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:59:57 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 17:23:43 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_action(void *void_philo)
{
	t_philos *philo;
	pthread_mutex_t lock;
	
	philo = (t_philos *)void_philo;
	while (1)
	{
		eaty_time(philo);
		thinky_time(philo);
		sleepy_time(philo);
	}
}

void	create_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].fork = i;
		data->philos[i].data = data;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_create(&data->philos[i].thread, NULL, philo_action, &data->philos[i]);
		i++;
	}
}

void	set_data(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_to_eat = ft_atoi(argv[5]);
	data->philos = malloc(sizeof(t_philos) * data->num_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
}

int main(int argc, char **argv)
{
	t_data data;

	set_data(&data, argv);
	create_philos(&data);
	while (1);
}
