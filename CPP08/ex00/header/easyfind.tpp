/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:17:04 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/21 17:16:21 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename T::const_iterator easyfind(T &container, int value)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == value)
        return (it);
    }
    throw(std::exception());
}

// template <typename T>
// typename T::iterator easyfind(T &container, int value)
// {
//     for (typename T::iterator it = container.begin(); it != container.end(); it++)
//     {
//         if (*it == value)
//         return (it);
//     }
//     throw(std::exception());
// }