/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:41 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/23 14:48:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
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