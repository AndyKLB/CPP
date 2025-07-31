/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:17:04 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/31 14:00:02 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::const_iterator easyfind(T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return (it);
    else
        throw(std::out_of_range("Out of range: Value not available in the list"));
}