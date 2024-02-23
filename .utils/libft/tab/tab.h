/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   *//*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:48:31 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/23 16:04:48 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include "../libft.h"

char		**ft_tabdup(char **tab);

char		**ft_tabjoin(char **tab, char *str, int free_tab, int free_str);

#endif
