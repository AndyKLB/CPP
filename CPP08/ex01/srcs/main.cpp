/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:25:28 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/22 15:10:04 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

int main()
{

    // Standard size with and without catch

    Span sp = Span(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        sp.addNumber(14);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Big size (100000) with and without catch

    std::vector<int> range(100000);
    for (unsigned int i = 0; i < 100000; i++)
        range[i] = i * 2;
    Span bigSpan(100000);
    try
    {
        bigSpan.addNumber(range.begin(), range.end());
        std::cout << bigSpan.shortestSpan() << std::endl;
        std::cout << bigSpan.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        bigSpan.addNumber(45);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    // Size too small with and without catch


    Span tooSmall(2);
    try
    {
        tooSmall.addNumber(6);
        std::cout << tooSmall.shortestSpan() << std::endl;
        std::cout << tooSmall.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        tooSmall.addNumber(10);
        std::cout << tooSmall.shortestSpan() << std::endl;
        std::cout << tooSmall.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}