/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:03:06 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/07 14:01:44 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"
#include "../header/RealType.hpp"

int main()
{
    Base *goodBasePtr = generate();
    std::cout << "Identify by pointer:" << std::endl;
    identify(goodBasePtr);
    std::cout << std::endl;

    std::cout << "Identify by reference:" << std::endl;
    identify(*goodBasePtr);
    std::cout << std::endl;

    D badBase;
    Base *badBasePtr = &badBase;
    std::cout << "Identify by pointer invalid base:" << std::endl;
    identify(badBasePtr);
    std::cout << std::endl;

    std::cout << "Identify by reference invalid base:" << std::endl;
    identify(*badBasePtr);
    std::cout << std::endl;
}
