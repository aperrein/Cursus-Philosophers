/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:08:47 by aperrein          #+#    #+#             */
/*   Updated: 2023/05/04 10:10:02 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	timer(void)
{
	long int		r;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_exit("Error\nGettimofday failed\n"));
	r = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (r);
}

void	print_status(char *s, t_p *ph)
{
	long int	time;
	int			i;

	i = 31 + (ph->id % 7);
	pthread_mutex_lock(&ph->all->m_end);
	pthread_mutex_lock(&ph->all->m_dead);
	time = timer() - ph->all->ti_start;
	if (ph->all->end != ph->all-> n_p && !ph->all->dead)
	{	
		if (!(ph->all->ti_die / 2 <= ph->all->ti_eat && time > ph->all->ti_die))
		{
			printf("\033[%dm""%ld Philo %d ", i, time, ph->id);
			printf("%s (ate %d times)\n""\033[00m", s, ph->ate);
		}
	}
	pthread_mutex_unlock(&ph->all->m_dead);
	pthread_mutex_unlock(&ph->all->m_end);
}
