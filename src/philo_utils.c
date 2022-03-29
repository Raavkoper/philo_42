/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 16:10:19 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/29 11:21:13 by rkoper        ########   odam.nl         */
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
