/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:50:13 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/17 11:32:43 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _size(0)
{
    std::cout << "Default constructor called (no parameters -> empty array)" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (_size == 0)
        _array = 0;
    else
        _array = new T[n];
    std::cout << "Sized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &src)
{
    _size = src._size;
    if (_size == 0)
        _array = 0;
    else
        _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
    std::cout << "Deep copy constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Default destructor called" << std::endl;

    delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (this != &rhs)
    {
        delete[] _array;
        _size = rhs._size;
        if (_size == 0)
            _array = 0;
        else
        {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = rhs._array[i];
        }
    }
    std::cout << "Equal operator assignement constructor called" << std::endl;
    return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return (_array[index]);
}

template <typename T>
const T *Array<T>::getArrayAdress() const
{
    return (_array);
}
