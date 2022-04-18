/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:15:18 by emakas            #+#    #+#             */
/*   Updated: 2022/04/18 15:53:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# include <signal.h>
# include <stdlib.h>
# include "../../lib/libft/libft.h"

void	ft_sendmsg(int pid, char *msg);
void	handle(int signal);

#endif