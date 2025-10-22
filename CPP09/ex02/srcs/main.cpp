/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:24:30 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/22 14:27:09 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

bool stringIsDigit(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[0] == '-')
            continue;
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

void parseArgument(int ac, char **av, std::vector<int> &numbersArgs)
{
    if (ac < 2)
        throw(std::runtime_error("Error: usage \"<./prog> <args>\""));
    for (int i = 1; i < ac; i++)
    {
        std::string args = av[i];
        char *pEnd;
        if (args.empty())
            throw(std::runtime_error("Error: empty"));
        long nbr;
        if (!stringIsDigit(args))
            throw(std::runtime_error("Error: is not digit"));
        nbr = strtol(args.c_str(), &pEnd, 10);
        if (nbr <= 0 || nbr > INT_MAX)
            throw(std::runtime_error("Error: overflow"));
        if (*pEnd)
            throw(std::runtime_error("Error: invalid arguments"));
        numbersArgs.push_back(static_cast<int>(nbr));
    }
    std::set<int> checkDouble;
    std::vector<int>::const_iterator it = numbersArgs.begin();
    for (; it < numbersArgs.end(); it++)
    {
        if (checkDouble.find((*it)) != checkDouble.end())
            throw(std::runtime_error("Error: duplicates numbers in args"));
        checkDouble.insert((*it));
    }
    return;
}
void compareRealSort(std::vector<int> &test, PmergeMe &merge)
{
    std::sort(test.begin(), test.end());

    for (size_t i = 0; i < test.size(); i++)
    {
        if (test[i] != merge.getVec()[i] || test[i] != merge.getDeque()[i])
            throw(std::logic_error("fail to sort"));
    }
}

int main(int ac, char **av)
{

    std::vector<int> numbersArgs;
    try
    {
        parseArgument(ac, av, numbersArgs);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    PmergeMe merge;
    std::vector<int>::const_iterator it = numbersArgs.begin();
    std::vector<int> test;
    for (; it < numbersArgs.end(); it++)
    {
        merge.addNumbersContainers((*it));
        test.push_back((*it));
    }
    merge.printBeforeSort();
    merge.sortVector();
    merge.sortDeque();
    try
    {
        compareRealSort(test, merge);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    merge.printAfterSort();
    merge.printTimeSort();
}