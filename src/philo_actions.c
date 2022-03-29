/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 13:56:28 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 14:02:27 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eaty_time(int id)
{
	printf("This hombre is in eaty time %d\n", id);
	sleep(2);
}

void	thinky_time(int id)
{
	printf("This hombre is in thinky time %d\n", id);
	sleep(1);
}

void	sleepy_time(int id)
{
	printf("This hombre is in sleepy time %d\n", id);
	sleep(1);
}