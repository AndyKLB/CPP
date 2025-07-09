/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:29:04 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/09 15:08:26 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RealType.hpp"

Base *generate(void)
{
    int nb;
    std::srand(std::time(0)); // init rand
    nb = std::rand() % 3; // genere un chiffre entre 0 et 2
    if (nb == 0)
        return (new (A));
    else if (nb == 1)
        return (new (B));
    else
        return (new (C));
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "Type: A" << std::endl;
        return;
    }
    catch (std::bad_cast &e)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "Type: B" << std::endl;
        return;
    }
    catch (std::bad_cast &e)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "Type: C" << std::endl;
        return;
    }
    catch (std::bad_cast &e)
    {
    }
    std::cout << "Unknown type: std::bad_cast" << std::endl;
}