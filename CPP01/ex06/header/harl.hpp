/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:41 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/23 16:12:57 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_FILTER_HPP
#define HARL_FILTER_HPP
#include <iostream>

class Harl
{
public:
    Harl();
    ~Harl();
    void complain(std::string level);

private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};

#endif