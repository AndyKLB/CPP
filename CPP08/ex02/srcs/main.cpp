/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:25:05 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/23 16:49:17 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MutantStack.hpp"

int main()
{
    std::cout << "-----MutantStack test-----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top element(last): " << std::endl;
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size after pop: " << std::endl;
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it; // to test increment and decrement operators if not compilation error
    std::cout << "MutantStack contents:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); // check if MutantStack is compatible with stack
    std::cout << std::endl;

    std::cout << "-----List test-----" << std::endl;
    std::list<int> lis;
    lis.push_back(5);
    lis.push_back(17);
    std::cout << "back element(last): " << std::endl;
    std::cout << lis.back() << std::endl;
    lis.pop_back();
    std::cout << "size after pop: " << std::endl;
    std::cout << lis.size() << std::endl;
    lis.push_back(3);
    lis.push_back(5);
    lis.push_back(737);
    lis.push_back(0);
    std::list<int>::iterator listIt = lis.begin();
    std::list<int>::iterator listIte = lis.end();
    ++listIt;
    --listIt;
    std::cout << "List contents:" << std::endl;
    while (listIt != listIte)
    {
        std::cout << *listIt << std::endl;
        ++listIt;
    }
    return 0;
}