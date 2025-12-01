/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:28:11 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/01 17:29:40 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	put_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	return (0);
}

int	exit_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	return (1);
}
