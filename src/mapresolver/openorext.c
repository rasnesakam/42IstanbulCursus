/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openorext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:18:29 by emakas            #+#    #+#             */
/*   Updated: 2022/07/31 20:03:31 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

int	openorext(char *maddr)
{
	int	fd;
	int	cmp;

	fd = open(maddr, O_RDONLY);
	if (fd < 0)
		ft_exit ("FILE ERROR:", NULL, errno);
	if (ft_strrchr (maddr, '.') == NULL)
		ft_exit ("FILE FORMAT NOT SUPPORTED", NULL, EINVAL);
	cmp = ft_strncmp (ft_strrchr (maddr, '.'),
			".ber", ft_strlen (maddr) + ft_strlen (".ber"));
	if (cmp != 0)
		ft_exit ("FILE FORMAT NOT SUPPORTED", NULL, EINVAL);
	return (fd);
}
