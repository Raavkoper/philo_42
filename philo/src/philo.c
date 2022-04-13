/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:59:57 by rkoper        #+#    #+#                 */
/*   Updated: 2022/04/13 16:58:09 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_action(void *void_philo)
{
	t_philos	*philo;

	philo = (t_philos *)void_philo;
	if (philo->data->num_philos == 1)
	{
		pthread_mutex_lock(&philo->data->forks[check_right(philo)]);
		print_action(philo, 'f', check_right(philo));
		return (NULL);
	}
	if (philo->id % 2)
		usleep(philo->data->time_to_eat * 1000);
	while (!philo->data->died && philo->meals_left)
	{
		eaty_time(philo);
		if (!philo->meals_left)
			return (NULL);
		print_action(philo, 's', 0);
		ft_sleep(philo->data->time_to_sleep, philo->data);
		print_action(philo, 't', 0);
	}
	return (NULL);
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal = time_stamp();
		data->philos[i].meals_left = data->times_to_eat;
		data->philos[i].data = data;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_create(&data->philos[i].thread, NULL, philo_action, \
		&data->philos[i]);
		i++;
	}
	check_dead(data);
	finish_process(data);
}

int	set_data(t_data *data, char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 \
		|| ft_atoi(argv[4]) < 0)
	{
		printf("input error\n");
		return (0);
	}
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_to_eat = ft_atoi(argv[5]);
	data->died = 0;
	pthread_mutex_init(&data->eating, NULL);
	pthread_mutex_init(&data->writing, NULL);
	data->philos = malloc(sizeof(t_philos) * data->num_philos);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
	{
		free(data->philos);
		return (0);
	}
	data->start = time_stamp();
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (set_data(&data, argv))
			create_philos(&data);
	}
	else
		printf("invalid amount of arguments given\n");
}
