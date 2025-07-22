/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:17:11 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/21 17:21:50 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/easyfind.hpp"

int main()
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(45);
    list.push_back(341);
    list.push_back(48);
    list.push_back(25);


    std::cout << "trying with list with two avalaible value and an unavailable value:" << std::endl;
    try
    {
        easyfind(list, 48);
        std::cout << "Searching for value is equal to 341 | easyfind = " << *easyfind(list, 341) << std::endl;
        easyfind(list, 1111);
    }
    catch (const std::exception &e)
    {
        std::cerr << "value not available in the list" << '\n';
    }
    std::cout << std::endl;

    std::deque<int> deque;

    deque.push_back(2463);
    deque.push_back(24);
    deque.push_back(243);
    deque.push_back(2);
    deque.push_back(63);

    std::cout << "trying with deque with two avalaible values and an unavailable value:" << std::endl;
    try
    {
        easyfind(deque, 2463);
        std::cout << "Searching for value is equal to 24 | easyfind = " << *easyfind(deque, 24) << std::endl;
        easyfind(deque, 12463);
    }
    catch (const std::exception &e)
    {
        std::cerr << "value not available in the list" << '\n';
    }
    std::cout << std::endl;

    std::vector<int> vector;

    vector.push_back(2463);
    vector.push_back(24);
    vector.push_back(243);
    vector.push_back(2);
    vector.push_back(63);

    std::cout << "trying with vector with two avalaible values and an unavailable value:" << std::endl;
    try
    {
        easyfind(vector, 2463);
        std::cout << "Searching for value is equal to 2463 | easyfind = " << *easyfind(vector, 2463) << std::endl;
        easyfind(vector, 12463);
    }
    catch (const std::exception &e)
    {
        std::cerr << "value not available in the list" << '\n';
    }
}