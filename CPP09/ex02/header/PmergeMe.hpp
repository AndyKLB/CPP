/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:08 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/14 14:28:19 by ankammer         ###   ########.fr       */
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
    // sort with vector
    const std::vector<int> generateJacobsthalVec(int sizePending) const;
    const std::vector<int> setOrderInsertVec(int size);
    void generateJackOrderVec(size_t size, std::vector<int> &jacSuite, std::vector<int> &jackOrder);

    // sort with dequeu
    // const std::deque<int> generateJacobsthalDeq(int size) const;
    // void generateJackOrderDeq(int start, int size, std::deque<int> &jacSuite, std::deque<int> &jackOrder);
    // const std::deque<int> setOrderInsertDeq(int size);
    
    std::vector<int> _vector;
    std::deque<int> _deque;
    double _dequeTime;
    double _vectorTime;
};

#endif