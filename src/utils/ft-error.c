/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:35:38 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 09:23:42 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_error(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
	exit(1);
}
