/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/09 15:39:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Data.hpp"
#include "../header/Serializer.hpp"

int main()
{
    Data data;
    data.age = 42;
    data.name = "Marvin";
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialization: " << std::endl
              << "   serialized Data: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);
    if (deserialized == &data)
    {
        std::cout << "Deserialization succeed:" << std::endl
                  << "   address Data: " << &data << std::endl
                  << "   address deserialised Data: " << deserialized << std::endl;
        std::cout << "Data:" << std::endl
                  << "   Name: " << data.name << std::endl
                  << "   Age: " << data.age << std::endl;
        std::cout << "Deserialised Data: " << std::endl
                  << "   Name: " << deserialized->name << std::endl
                  << "   Age: " << deserialized->age << std::endl;
    }
    else
        std::cerr << "Deserialization failed" << std::endl;
    return (0);
}