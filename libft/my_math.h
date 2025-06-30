/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:55:10 by edgribei          #+#    #+#             */
/*   Updated: 2025/06/16 19:54:13 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MATH_H
# define MY_MATH_H

int		clamp(const int num, const int min, const int max);
float	clampf(const float num, const float min, const float max);
int		lerp(const int a, const int b, const float t);
int		max(const int a, const int b);
int		min(const int a, const int b);
int		abs(const int a);
#endif
