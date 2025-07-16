/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:45:32 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/16 14:50:28 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Array.hpp"

int main()
{
    Array<char> charTab;
    Array<int> intTab;
    if (charTab.size() == 0 && intTab.size() == 0)
        std::cout << "Template with init array to 0 worked well!" << std::endl;
    std::cout << std::endl;

    Array<float> floatTab(5);
    std::cout << "Size of floatTab = " << floatTab.size() << " and should be 5 which mean that sized constructor worked well!" << std::endl;
    for (unsigned int i = 0; i < floatTab.size(); i++)
    {
        floatTab[i] = i + 0.5; // possible grace a la surcharge de "[]"
        std::cout << floatTab[i] << " overload of \"[]\" worked well!" << std::endl;
    }
    std::cout << std::endl;

    Array<float> equalConst;
    equalConst = floatTab;
    for (unsigned int i = 0; i < equalConst.size(); i++)
        std::cout << "equalConst = " << equalConst[i] << " | floatTab = " << floatTab[i] << std::endl;
    std::cout << "if all value are equal operator \"=\" worked well!" << std::endl;
    std::cout << std::endl;

    Array<float> copyConst(equalConst);
    std::cout << "equalConst adress = " << &equalConst << " | copyConst adress = " << &copyConst << std::endl;
    copyConst[0] = 42;
    for (unsigned int i = 0; i < copyConst.size(); i++)
        std::cout << "equalConst = " << equalConst[i] << " | copyConst = " << copyConst[i] << std::endl;
    std::cout << "if all value are equal, except index [0], and adress are different copy constructor with deep copy worked well!" << std::endl;
    std::cout << std::endl;

    // const Array<float> constCopy(copyConst);
    try
    {
        // constCopy[0] = 2; // impossible en ecriture car const, usage "[]" const
        copyConst[80] = 55;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception catched: Affectation out of limits" << '\n';
    }

    try
    {
    //   std::cout <<  constCopy[0] << std::endl; // possible pour la lecture
      std::cout <<  copyConst[80] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception catched: Read out of limits" << '\n';
    }
    std::cout << std::endl;
}