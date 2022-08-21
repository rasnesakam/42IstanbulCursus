/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_verifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:39:12 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 09:55:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_VERIFIER_H
# define ARG_VERIFIER_H
# include <libft.h>
# include "../utils/utils.h"

int		verify_args(int ac, char **args);
int		verify_arg(char *arg);
void	check_args(char **av, int ac );
#endif