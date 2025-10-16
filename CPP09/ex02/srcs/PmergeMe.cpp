/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/16 14:32:19 by ankammer         ###   ########.fr       */
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
    std::cout << "Before with vector: ";
    std::vector<int>::const_iterator it = _vector.begin();
    for (; it != _vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Before with deque: ";
    std::deque<int>::const_iterator ite = _deque.begin();
    for (; ite != _deque.end(); ++ite)
        std::cout << *ite << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}
void PmergeMe::printAfterSort()
{
    std::cout << "After with vector: ";
    std::vector<int>::const_iterator it = _vector.begin();
    for (; it != _vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "After with deque: ";
    std::deque<int>::const_iterator ite = _deque.begin();
    for (; ite != _deque.end(); ++ite)
        std::cout << *ite << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}
void PmergeMe::printTimeSort()
{
    std::cout << "Time to process a range of " << _vector.size() << " " << "elements with std::vector: " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " " << "elements with std::deque: " << _dequeTime << " us" << std::endl;
}

void printVec(const std::vector<int> &jackOrder, const std::string title)
{
    std::vector<int>::const_iterator it = jackOrder.begin();
    std::cout << title << ": ";
    for (; it != jackOrder.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> > &jackOrder, const std::string title)
{
    std::vector<std::pair<int, int> >::const_iterator it = jackOrder.begin();
    std::cout << title << ": ";
    for (; it != jackOrder.end(); ++it)
        std::cout << "[" << (*it).first << "," << (*it).second << "]" << " ";
    std::cout << std::endl;
}
// sort vector

void PmergeMe::generateJacobsthalVec(int size, std::vector<int> &jacSuite) const
{
    jacSuite.push_back(0);
    jacSuite.push_back(1);
    while (jacSuite.back() < size)
    {

        if (jacSuite[jacSuite.size() - 1] + (jacSuite[jacSuite.size() - 2] * 2) >= size)
            break;
        jacSuite.push_back(jacSuite[jacSuite.size() - 1] + (jacSuite[jacSuite.size() - 2] * 2));
    }
}

void PmergeMe::generateJackOrderVec(size_t size, std::vector<int> &jacSuite, std::vector<int> &jackOrder)
{
    int tmp = 0;
    for (size_t i = 3; i < jacSuite.size(); ++i)
    {
        size_t index = jacSuite[i];
        if (index >= size)
            break;
        jackOrder.push_back(index);

        for (int j = index - 1; j > jacSuite[i - 1]; --j)
            jackOrder.push_back(j);
        tmp = index;
    }
    for (int k = size; k > tmp; --k)
        jackOrder.push_back(k);
}

int PmergeMe::binSearchVec(std::vector<int> &mainChain, int target, size_t start, size_t end)
{
    int midInsertPos;

    midInsertPos = start + (end - start) / 2;
    while (start <= end)
    {
        midInsertPos = start + (end - start) / 2;
        if (target == mainChain.at(midInsertPos))
            return (midInsertPos);
        if (midInsertPos == 0)
        {
            if (target > mainChain[midInsertPos])
            {
                midInsertPos = 1;
                break;
            }
            else
            {
                midInsertPos = 0;
                break;
            }
        }
        if (target > mainChain[midInsertPos])
        {
            start = midInsertPos + 1;
        }
        else
            end = midInsertPos - 1;
    }
    if (target < mainChain[midInsertPos])
        return (midInsertPos);
    else
        return (midInsertPos + 1);
}

void PmergeMe::setOrderInsertVec(int size, std::vector<int> &jackOrder, std::vector<int> &remainChain, std::vector<int> &mainChain)
{
    std::vector<int> jacSuite;
    generateJacobsthalVec(size, jacSuite);
    generateJackOrderVec(size, jacSuite, jackOrder);
    std::vector<int>::const_iterator it = jackOrder.begin();
    size_t syncPairPos = 0;
    size_t endPos;
    size_t insertPos;
    int target;
    mainChain.insert(mainChain.begin(), remainChain[0]);
    for (; it < jackOrder.end(); ++it)
    {
        target = remainChain[(*it - 1)];
        endPos = *it + syncPairPos;
        insertPos = binSearchVec(mainChain, target, 0, endPos);
        mainChain.insert(mainChain.begin() + insertPos, target);
        syncPairPos++;
    }
}

void PmergeMe::makeChainsVec(std::vector<std::pair<int, int> > &pairs, std::vector<int> &mainChain, std::vector<int> &remainChain)
{
    if (pairs.empty())
        return;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        remainChain.push_back(pairs[i].second);
    }
}

void PmergeMe::mergePairsVec(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right)
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

void PmergeMe::sortPairVec(std::vector<std::pair<int, int> > &pairs, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    sortPairVec(pairs, left, mid);      // parti gauche
    sortPairVec(pairs, mid + 1, right); // parti droite
    mergePairsVec(pairs, left, mid, right);
}
void PmergeMe::setPairVec(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
            pairs.push_back((std::make_pair(_vector[i], _vector[i + 1])));
        else
            pairs.push_back((std::make_pair(_vector[i + 1], _vector[i])));
    }
}

void PmergeMe::sortVector()
{
    clock_t begin = clock();
    std::vector<int> mainChain;
    std::vector<int> remainChain;
    bool hasRest = (_vector.size() % 2);
    int rest = hasRest ? _vector.back() : 0;
    if (_vector.size() <= 1)
    {
        std::cout << _vector.back() << std::endl;
        return;
    }
    std::vector<std::pair<int, int> > pairs;
    setPairVec(pairs);
    sortPairVec(pairs, 0, pairs.size() - 1);
    makeChainsVec(pairs, mainChain, remainChain);
    std::vector<int> jackOrder;
    setOrderInsertVec(remainChain.size(), jackOrder, remainChain, mainChain);
    if (hasRest)
    {
        int insertPos = binSearchVec(mainChain, rest, 0, mainChain.size() - 1);
        mainChain.insert(mainChain.begin() + insertPos, rest);
    }
    _vector = mainChain;
    clock_t end = clock();
    _vectorTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000000;
}

// sort dequeu

void PmergeMe::generateJacobsthalDeq(int size, std::deque<int> &jacSuite) const
{
    jacSuite.push_back(0);
    jacSuite.push_back(1);
    while (jacSuite.back() < size)
    {

        if (jacSuite[jacSuite.size() - 1] + (jacSuite[jacSuite.size() - 2] * 2) >= size)
            break;
        jacSuite.push_back(jacSuite[jacSuite.size() - 1] + (jacSuite[jacSuite.size() - 2] * 2));
    }
}

void PmergeMe::generateJackOrderDeq(size_t size, std::deque<int> &jacSuite, std::deque<int> &jackOrder)
{
    int tmp = 0;
    for (size_t i = 3; i < jacSuite.size(); ++i)
    {
        size_t index = jacSuite[i];
        if (index >= size)
            break;
        jackOrder.push_back(index);

        for (int j = index - 1; j > jacSuite[i - 1]; --j)
            jackOrder.push_back(j);
        tmp = index;
    }
    for (int k = size; k > tmp; --k)
        jackOrder.push_back(k);
}

int PmergeMe::binSearchDeq(std::deque<int> &mainChain, int target, size_t start, size_t end)
{
    int midInsertPos;

    midInsertPos = start + (end - start) / 2;
    while (start <= end)
    {
        midInsertPos = start + (end - start) / 2;
        if (target == mainChain.at(midInsertPos))
            return (midInsertPos);
        if (midInsertPos == 0)
        {
            if (target > mainChain[midInsertPos])
            {
                midInsertPos = 1;
                break;
            }
            else
            {
                midInsertPos = 0;
                break;
            }
        }
        if (target > mainChain[midInsertPos])
        {
            start = midInsertPos + 1;
        }
        else
            end = midInsertPos - 1;
    }
    if (target < mainChain[midInsertPos])
        return (midInsertPos);
    else
        return (midInsertPos + 1);
}

void PmergeMe::setOrderInsertDeq(int size, std::deque<int> &jackOrder, std::deque<int> &remainChain, std::deque<int> &mainChain)
{
    std::deque<int> jacSuite;
    generateJacobsthalDeq(size, jacSuite);
    generateJackOrderDeq(size, jacSuite, jackOrder);
    std::deque<int>::const_iterator it = jackOrder.begin();
    size_t syncPairPos = 0;
    size_t endPos;
    size_t insertPos;
    int target;
    mainChain.insert(mainChain.begin(), remainChain[0]);
    for (; it < jackOrder.end(); ++it)
    {
        target = remainChain[(*it - 1)];
        endPos = *it + syncPairPos;
        insertPos = binSearchDeq(mainChain, target, 0, endPos);
        mainChain.insert(mainChain.begin() + insertPos, target);
        syncPairPos++;
    }
}

void PmergeMe::makeChainsDeq(std::deque<std::pair<int, int> > &pairs, std::deque<int> &mainChain, std::deque<int> &remainChain)
{
    if (pairs.empty())
        return;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        remainChain.push_back(pairs[i].second);
    }
}

void PmergeMe::mergePairsDeq(std::deque<std::pair<int, int> > &pairs, int left, int mid, int right)
{
    std::deque<std::pair<int, int> > leftPairs(pairs.begin() + left, pairs.begin() + mid + 1);
    std::deque<std::pair<int, int> > rightPairs(pairs.begin() + mid + 1, pairs.begin() + right + 1);

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

void PmergeMe::sortPairDeq(std::deque<std::pair<int, int> > &pairs, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    sortPairDeq(pairs, left, mid);      // parti gauche
    sortPairDeq(pairs, mid + 1, right); // parti droite
    mergePairsDeq(pairs, left, mid, right);
}
void PmergeMe::setPairDeq(std::deque<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        if (_deque[i] > _deque[i + 1])
            pairs.push_back((std::make_pair(_deque[i], _deque[i + 1])));
        else
            pairs.push_back((std::make_pair(_deque[i + 1], _deque[i])));
    }
}

void PmergeMe::sortDeque()
{
    clock_t begin = clock();
    std::deque<int> mainChain;
    std::deque<int> remainChain;
    bool hasRest = (_deque.size() % 2);
    int rest = hasRest ? _deque.back() : 0;
    if (_deque.size() <= 1)
    {
        std::cout << _deque.back() << std::endl;
        return;
    }
    std::deque<std::pair<int, int> > pairs;
    setPairDeq(pairs);
    sortPairDeq(pairs, 0, pairs.size() - 1);
    makeChainsDeq(pairs, mainChain, remainChain);
    std::deque<int> jackOrder;
    setOrderInsertDeq(remainChain.size(), jackOrder, remainChain, mainChain);
    if (hasRest)
    {
        int insertPos = binSearchDeq(mainChain, rest, 0, mainChain.size() - 1);
        mainChain.insert(mainChain.begin() + insertPos, rest);
    }
    _deque = mainChain;
    clock_t end = clock();
    _dequeTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000000;
}