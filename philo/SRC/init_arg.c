/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:09:42 by aperrein          #+#    #+#             */
/*   Updated: 2023/05/02 12:21:07 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_exit(char *s)
{
	printf("%s", s);
	return (1);
}

int	check_arg(int ac, char *av[])
{
	int			i;
	int			m;
	long int	r;

	m = 1;
	while (m < ac)
	{
		i = 0;
		r = 0;
		if (av[m][0] == '-')
			return (ft_exit("Error\nNegative number\n"));
		if (av[m][0] == '+')
			i++;
		while (av[m][i])
		{
			if (av[m][i] < '0' || av[m][i] > '9')
				return (ft_exit("Error\nNot number\n"));
			r = r * 10 + av[m][i++] - '0';
			if (r > 2147483647)
				return (ft_exit("Error\nNot int\n"));
		}
		m++;
	}
	return (0);
}

int	init_arg(int ac, char *av[], t_all *all)
{
	if (ac < 5)
		return (ft_exit("Error\nNot enought arg\n"));
	else if (ac > 6)
		return (ft_exit("Error\nToo much args\n"));
	if (check_arg(ac, av))
		return (1);
	if (ft_atoi(av[1]) == 0)
		return (ft_exit("Error\nAt least 1 philosopher\n"));
	all->end = 0;
	all->n_p = ft_atoi(av[1]);
	all->ti_die = ft_atoi(av[2]);
	all->ti_eat = ft_atoi(av[3]);
	all->ti_sleep = ft_atoi(av[4]);
	all->dead = 0;
	if (ac == 5)
		all->n_must_eat = -1;
	else
		all->n_must_eat = ft_atoi(av[5]);
	all->ph = malloc(sizeof(t_p) * all->n_p);
	if (!all->ph)
		return (ft_exit("Error\nMalloc\n"));
	return (0);
}
