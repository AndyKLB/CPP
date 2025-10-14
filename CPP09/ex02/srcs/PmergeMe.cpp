/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/14 15:10:30 by ankammer         ###   ########.fr       */
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

void PmergeMe::addNumbersContainers(int number)
{
    _vector.push_back(number);
    _deque.push_back(number);
}

void PmergeMe::printBeforeSort()
{
    std::cout << "Before: "; // vector: ";
    std::vector<int>::const_iterator it = _vector.begin();
    for (; it != _vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // std::cout << "Before deque: ";
    // std::deque<int>::const_iterator ite = _deque.begin();
    // for (; ite != _deque.end(); ++ite)
    //     std::cout << *ite << " ";
    // std::cout << std::endl;
}
void PmergeMe::printAfterSort()
{
    std::cout << "After: "; // vector: ";
    std::vector<int>::const_iterator it = _vector.begin();
    for (; it != _vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // std::cout << "After deque: ";
    // std::deque<int>::const_iterator ite = _deque.begin();
    // for (; ite != _deque.end(); ++ite)
    //     std::cout << *ite << " ";
    // std::cout << std::endl;
}
void PmergeMe::printTimeSort()
{
    std::cout << "Time to process a range of " << _vector.size() << " " << "elements with std::vector: " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " " << "elements with std::deque: " << _dequeTime << " us" << std::endl;
}
// est ce que j'affiche les prints after/before pour les 2 containers ou 1 suffit?

// sort vector

void printJackOrder(const std::vector<int> &jackOrder, const std::string title)
{
    std::vector<int>::const_iterator it = jackOrder.begin();
    std::cout << title << ": ";
    for (; it != jackOrder.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> > &jackOrder, const std::string title)
{
    std::vector<std::pair<int, int> >::const_iterator it = jackOrder.begin();
    std::cout << title << ": ";
    for (; it != jackOrder.end(); it++)
        std::cout << "[" << (*it).first << "," << (*it).second << "]" << " ";
    std::cout << std::endl;
}

const std::vector<int> PmergeMe::generateJacobsthalVec(int size) const
{
    std::vector<int> jacobSuite;
    jacobSuite.push_back(0);
    jacobSuite.push_back(1);
    while (jacobSuite.back() < size)
        jacobSuite.push_back(jacobSuite[jacobSuite.size() - 1] + (jacobSuite[jacobSuite.size() - 2] * 2));
    printJackOrder(jacobSuite, "jacobsuite");
    return (jacobSuite);
}

void PmergeMe::generateJackOrderVec(size_t size, std::vector<int> &jacSuite, std::vector<int> &jackOrder)
{
    int tmp = 0;
    for (size_t i = 3; i < jacSuite.size(); i++)
    {
        size_t index = jacSuite[i];
        if (index >= size)
            break;
        jackOrder.push_back(index);

        for (int j = index - 1; j > jacSuite[i - 1]; j--)
            jackOrder.push_back(j);
        tmp = index;
    }
    for (int k = size - 1; k > tmp; k--)
        jackOrder.push_back(k);
}

const std::vector<int> PmergeMe::setOrderInsertVec(int size)
{
    std::vector<int> jacSuite = generateJacobsthalVec(size);
    std::vector<int> jackOrder;
    generateJackOrderVec(size, jacSuite, jackOrder); // todo
    return (jackOrder);
}

void makeChains(std::vector<std::pair<int, int> > &pairs, std::vector<int> &mainChain, std::vector<int> &remainChain)
{
    if (pairs.empty())
        return;
    mainChain.push_back(pairs[0].second);
    mainChain.push_back(pairs[0].first);
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        remainChain.push_back(pairs[i].second);
    }
    printJackOrder(mainChain, "mainChain");
    printJackOrder(remainChain, "remainChain");
}

void mergePairs(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right)
{
    std::vector<std::pair<int, int> > leftPairs(pairs.begin() + left, pairs.begin() + mid + 1);
    std::vector<std::pair<int, int> > rightPairs(pairs.begin() + mid + 1, pairs.begin() + right + 1);

    size_t i = 0;    // iterer dans left
    size_t j = 0;    // iterer dans right
    size_t k = left; // partie a gauche des paires a trier

    while (i < leftPairs.size() && j < rightPairs.size())
    {
        if (leftPairs[i].first < rightPairs[j].first)
            pairs[k++] = leftPairs[i++];
        else
            pairs[k++] = rightPairs[j++];
    }
    while (i < leftPairs.size())
        pairs[k++] = leftPairs[i++];
    while (j < rightPairs.size())
        pairs[k++] = rightPairs[j++];
}



void sortPair(std::vector<std::pair<int, int> > &pairs, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    sortPair(pairs, left, mid);      // parti gauche
    sortPair(pairs, mid + 1, right); // parti droite
    mergePairs(pairs, left, mid, right);
}

void PmergeMe::sortVector()
{
    clock_t begin = clock();
    std::vector<int> mainChain;
    std::vector<int> remainChain;
    // bool hasRest = (_vector.size() % 2);
    // int rest = hasRest ? _vector.back() : 0;
    printJackOrder(_vector, "_vector");
    if (_vector.size() <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
            pairs.push_back((std::make_pair(_vector[i], _vector[i + 1])));
        else
            pairs.push_back((std::make_pair(_vector[i + 1], _vector[i])));
    }
    printPairs(pairs, "pairs before sort");
    sortPair(pairs, 0, pairs.size() - 1);
    printPairs(pairs, "pairs after sort");
    makeChains(pairs, mainChain, remainChain);
    std::vector<int> jackOrder = setOrderInsertVec(remainChain.size());
    printJackOrder(jackOrder, "jackorder");
    // if (hasRest)
    //     // todo
    //     _vector = mainChain;
    clock_t end = clock();
    _vectorTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000000;
}

// void PmergeMe::sortDeque()
// {
//     clock_t begin = clock();

//     clock_t end = clock();
//     _dequeTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000000;
// }
