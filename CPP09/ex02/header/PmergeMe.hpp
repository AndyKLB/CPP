/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:08 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/16 14:17:11 by ankammer         ###   ########.fr       */
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
    void generateJacobsthalVec(int size, std::vector<int> &jacSuite) const;
    void setOrderInsertVec(int size, std::vector<int> &jackOrder, std::vector<int> &remainChain, std::vector<int> &mainChain);
    void setPairVec(std::vector<std::pair<int, int> > &pairs);
    void generateJackOrderVec(size_t size, std::vector<int> &jacSuite, std::vector<int> &jackOrder);
    void sortPairVec(std::vector<std::pair<int, int> > &pairs, int left, int right);
    void mergePairsVec(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right);
    void makeChainsVec(std::vector<std::pair<int, int> > &pairs, std::vector<int> &mainChain, std::vector<int> &remainChain);
    int binSearchVec(std::vector<int> &mainChain, int target, size_t start, size_t end);

    // sort with dequeu
    void setPairDeq(std::deque<std::pair<int, int> > &pairs);
    void sortPairDeq(std::deque<std::pair<int, int> > &pairs, int left, int right);
    void mergePairsDeq(std::deque<std::pair<int, int> > &pairs, int left, int mid, int right);
    void makeChainsDeq(std::deque<std::pair<int, int> > &pairs, std::deque<int> &mainChain, std::deque<int> &remainChain);
    void setOrderInsertDeq(int size, std::deque<int> &jackOrder, std::deque<int> &remainChain, std::deque<int> &mainChain);
    int binSearchDeq(std::deque<int> &mainChain, int target, size_t start, size_t end);
    void generateJackOrderDeq(size_t size, std::deque<int> &jacSuite, std::deque<int> &jackOrder);
    void generateJacobsthalDeq(int size, std::deque<int> &jacSuite) const;

    std::vector<int> _vector;
    std::deque<int> _deque;
    double _dequeTime;
    double _vectorTime;
};

#endif