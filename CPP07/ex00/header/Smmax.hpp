/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smmax.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:59:37 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/14 14:15:14 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMMAX_TEMPLATE_TPP
#define SMMAX_TEMPLATE_TPP
#include <iostream>

template<typename T>
void swap(T & x, T & y)
{
    T tmp = x;
    x = y;
    y = tmp;    
}

template<typename T>
const T & min(const T & x, const T & y)
{
    return(x <= y ? x : y);
}
template<typename T>
const T & max(const T & x, const T & y)
{
    return(x >= y ? x : y);
}



#endif