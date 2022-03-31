/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:59:57 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/31 13:52:34 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_action(void *void_philo)
{
	t_philos *philo;
	
	philo = (t_philos *)void_philo;
	if (philo->data->num_philos == 1)
		print_action(philo->data->philos, 'd', 0);
	if (philo->id % 2)
		usleep(philo->data->time_to_eat * 1000);
	while (1 && philo->data->times_to_eat != 0 && !philo->data->state)
	{
		eaty_time(philo);
		print_action(philo, 's', 0);
		usleep(philo->data->time_to_sleep * 1000);
		print_action(philo, 't', 0);
	}
	return (NULL);
}

void	create_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal = 0;
		data->philos[i].prev_meal = 0;
		data->philos[i].data = data;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_create(&data->philos[i].thread, NULL, philo_action, &data->philos[i]);
		i++;
	}
	while (!data->state)
		check_dead(data);
}

void	set_data(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_to_eat = ft_atoi(argv[5]) * data->num_philos;
	data->state = 0;
	pthread_mutex_init(&data->right, NULL);
	pthread_mutex_init(&data->is_dead, NULL);
	data->philos = malloc(sizeof(t_philos) * data->num_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->start = time_stamp();
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 5 || argc == 6)
		set_data(&data, argv);
	else
	{
		printf("Invalid arguments given\n");
		exit(1);
	}
	create_philos(&data);
	while (1)
	{
		printf("%d\n", data.state);
		sleep(1);
	}
}
