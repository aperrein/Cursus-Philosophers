/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:55 by aperrein          #+#    #+#             */
/*   Updated: 2023/05/04 09:55:58 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_p *ph)
{
	int			d;
	long int	time;

	d = 0;
	pthread_mutex_lock(&ph->all->m_dead);
	if (timer() - ph->last_ate >= ph->all->ti_die && !ph->all->dead)
	{
		d = 1;
		ph->all->dead = d;
	}	
	time = ph->last_ate - ph->all->ti_start + ph->all->ti_die;
	if (d && ph->all->n_must_eat != ph->ate)
		printf("%ld Philo %d died\n", time, ph->id);
	if (ph->all->dead)
		ph->ate = ph->all->n_must_eat;
	pthread_mutex_unlock(&ph->all->m_dead);
}

void	same_routine(t_p *ph)
{
	check_death(ph);
	pthread_mutex_lock(&ph->all->m_dead);
	if (!ph->all->dead)
		ph->last_ate = timer();
	pthread_mutex_unlock(&ph->all->m_dead);
	print_status("has taken a fork", ph);
	pthread_mutex_lock(&ph->all->m_dead);
	if (!ph->all->dead)
		ph->ate++;
	pthread_mutex_unlock(&ph->all->m_dead);
	check_death(ph);
	print_status("is eating", ph);
	if (ph->ate == ph->all->n_must_eat)
	{
		pthread_mutex_lock(&ph->all->m_end);
		ph->all->end++;
		pthread_mutex_unlock(&ph->all->m_end);
	}
	usleep(1000 * ph->all->ti_eat);
}

void	impair_routine(t_p *ph)
{
	while (ph->ate < ph->all->n_must_eat
		|| (ph->all->n_must_eat == -1 && ph->ate != -1))
	{
		usleep(ph->all->ti_die * 10);
		pthread_mutex_lock(&ph->left);
		check_death(ph);
		print_status("has taken a fork", ph);
		pthread_mutex_lock(ph->right);
		same_routine(ph);
		pthread_mutex_unlock(ph->right);
		pthread_mutex_unlock(&ph->left);
		check_death(ph);
		print_status("is sleeping", ph);
		usleep(1000 * ph->all->ti_sleep);
		check_death(ph);
		print_status("is thinking", ph);
	}
}

void	pair_routine(t_p *ph)
{
	while (ph->ate < ph->all->n_must_eat
		|| (ph->all->n_must_eat == -1 && ph->ate != -1))
	{
		pthread_mutex_lock(ph->right);
		check_death(ph);
		print_status("has taken a fork", ph);
		pthread_mutex_lock(&ph->left);
		same_routine(ph);
		pthread_mutex_unlock(&ph->left);
		pthread_mutex_unlock(ph->right);
		check_death(ph);
		print_status("is sleeping", ph);
		usleep(1000 * ph->all->ti_sleep);
		check_death(ph);
		print_status("is thinking", ph);
	}
}

void	*thread_routine(void *data)
{
	t_p	*ph;

	ph = (t_p *)data;
	if (ph->id % 2 == 0)
		pair_routine(ph);
	else
		impair_routine(ph);
	return (NULL);
}
