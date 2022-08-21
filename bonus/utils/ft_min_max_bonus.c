/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:35:35 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 05:04:35 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int integer1, int integer2)
{
	if (integer1 < integer2)
		return (integer1);
	return (integer2);
}

int	ft_max(int integer1, int integer2)
{
	if (integer1 >= integer2)
		return (integer1);
	else
		return (integer2);
}
