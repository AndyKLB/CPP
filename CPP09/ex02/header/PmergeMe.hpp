/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:08 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/08 13:41:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_CLASS
#define PMERGE_ME_CLASS

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <set>
#include <cctype>
#include <climits>
#include <limits>
#include <algorithm>
#include <ctime>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();

    void addNumbersContainers(int number);
    void sortDeque();
    void sortVector();

    void printBeforeSort();
    void printAfterSort();
    void printTimeSort();

private:
    const std::vector<int> generateJacobsthalVec(int sizePending) const;
    const std::deque<int> generateJacobsthalDeq(int sizePending) const;
    std::vector<int> _vector;
    std::deque<int> _deque;
    double _dequeTime;
    double _vectorTime;
};

#endif