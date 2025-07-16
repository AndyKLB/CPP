/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:38:27 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/14 15:48:20 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Iter.hpp"

int main()
{
    int arrayInt[] = {0, 1, 2, 3};
    float arrayFloat[] = {0.45, 1.54, 2.45, 3};
    std::string arrayStr[] = {"salut", "ca", "va", "?"};
    
    iter(arrayInt, sizeof(arrayInt)/sizeof(arrayInt[0]), printArray<int>);
    iter(arrayFloat, sizeof(arrayFloat)/sizeof(arrayFloat[0]), printArray<float>);
    iter(arrayStr, sizeof(arrayStr)/sizeof(arrayStr[0]), printArray<std::string>);
}