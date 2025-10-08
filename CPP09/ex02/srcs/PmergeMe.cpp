/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/08 14:44:37 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src) : _vector(src._vector), _deque(src._deque), _dequeTime(src._dequeTime), _vectorTime(src._vectorTime)
{
}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->_deque = rhs._deque;
        this->_dequeTime = rhs._dequeTime;
        this->_vector = rhs._vector;
        this->_vectorTime = rhs._vectorTime;
    }
    return (*this);
}
PmergeMe::~PmergeMe()
{
}

const std::vector<int> PmergeMe::generateJacobsthalVec(int sizePending) const
{
    std::vector<int> jacobSuite;
    jacobSuite.push_back(0);
    jacobSuite.push_back(1);
    while (jacobSuite.back() < sizePending)
        jacobSuite.push_back(jacobSuite[jacobSuite.size() - 1] + (jacobSuite[jacobSuite.size() - 2] * 2));
    return (jacobSuite);
}
const std::deque<int> PmergeMe::generateJacobsthalDeq(int sizePending) const
{
    std::deque<int> jacobSuite;
    jacobSuite.push_back(0);
    jacobSuite.push_back(1);
    while (jacobSuite.back() < sizePending)
        jacobSuite.push_back(jacobSuite[jacobSuite.size() - 1] + (jacobSuite[jacobSuite.size() - 2] * 2));
    return (jacobSuite);
}

void PmergeMe::sortVector()
{
    clock_t begin = clock();
    std::vector<int> mainChain;
    std::vector<int> remainChain;
    int rest;
    std::vector<int>::const_iterator it = _vector.begin();
    std::vector<int>::const_iterator ite = _vector.begin() + 1;
    for(; ite < _vector.end(); it++, ite++)
    {
        mainChain.push_back((*it));
        remainChain.push_back((*ite));
    }
    if (_vector.size() % 2)
        rest = _vector.back();
    std::sort(remainChain.begin(), remainChain.end());
    // setOrderInsert(); // todo
    clock_t end = clock();
    _vectorTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000000;
}
void PmergeMe::sortDeque()
{
    clock_t begin = clock();
    std::deque<int> mainChain;
    std::deque<int> remainChain;
    int rest;
    std::deque<int>::const_iterator it = _deque.begin();
    std::deque<int>::const_iterator ite = _deque.begin() + 1;
    for(; ite < _deque.end(); it++, ite++)
    {
        mainChain.push_back((*it));
        remainChain.push_back((*ite));
    }
    if (_deque.size() % 2)
        rest = _deque.back();
    std::sort(remainChain.begin(), remainChain.end());
    // setOrderInsert(); // todo
    clock_t end = clock();
    _dequeTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000000;
}
void PmergeMe::addNumbersContainers(int number)
{
    _vector.push_back(number);
    _deque.push_back(number);
}

void PmergeMe::printBeforeSort()
{
    std::cout << "Before: "; // vector: ";
    std::vector<int>::const_iterator it = _vector.begin();
    for (; it < _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // std::cout << "Before deque: ";
    // std::deque<int>::const_iterator ite = _deque.begin();
    // for (; ite < _deque.end(); ite++)
    //     std::cout << *ite << " ";
    // std::cout << std::endl;
}
void PmergeMe::printAfterSort()
{
    std::cout << "After: "; // vector: ";
    std::vector<int>::const_iterator it = _vector.begin();
    for (; it < _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // std::cout << "After deque: ";
    // std::deque<int>::const_iterator ite = _deque.begin();
    // for (; ite < _deque.end(); ite++)
    //     std::cout << *ite << " ";
    // std::cout << std::endl;
}
void PmergeMe::printTimeSort()
{
    std::cout << "Time to process a range of " << _vector.size() << " " << "elements with std::vector: " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " " << "elements with std::deque: " << _dequeTime << " us" << std::endl;
}
// est ce que j'affiche les prints after/before pour les 2 containers ou 1 suffit?