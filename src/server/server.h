/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:03:35 by emakas            #+#    #+#             */
/*   Updated: 2022/04/10 16:34:48 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../../lib/libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	handle(int signal);

#endif