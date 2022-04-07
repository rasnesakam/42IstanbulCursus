/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:15:18 by emakas            #+#    #+#             */
/*   Updated: 2022/04/07 11:00:39 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# include <signal.h>
# include <stdlib.h>
# include "../../lib/libft/libft.h"

void	ft_sendmsg(int pid, char *msg);

#endif