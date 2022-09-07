/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_verifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:39:12 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 15:48:03 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_VERIFIER_H
# define ARG_VERIFIER_H
# include "../utils.h"

int	verify_args(int ac, char **args);
int	verify_arg(char *arg);

#endif