/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:11:58 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/22 18:12:13 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{

    std::string newFilename;
    std::string filename;
    std::string toReplace;
    std::string replacingStr;
    std::string buffer;
    size_t pos;

    if (argc != 4)
    {
        std::cout << "invalid argument enter <filename> <to_replace> <replacing string>" << std::endl;
        return (1);
    }
    filename = argv[1];
    toReplace = argv[2];
    replacingStr = argv[3];

    if (filename.empty() || toReplace.empty() || replacingStr.empty())
        std::cout << "error: you cannot provide an empty string" << std::endl;
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
        std::cout << "error opening infile" << std::endl;
    else
    {
        newFilename = filename + ".replace";
        std::ofstream ofs(newFilename.c_str());
        if (!ofs.is_open())
        {
            std::cout << "error creating outfile" << std::endl;
            ifs.close();
            return (1);
        }
        if (getline(ifs, buffer, '\0'))
        {
            for (pos = buffer.find(toReplace); pos != std::string::npos; pos = buffer.find(toReplace))
            {
                buffer.erase(pos, toReplace.size());
                buffer.insert(pos, replacingStr);
            }
            ofs << buffer;
        }
        ofs.close();
        ifs.close();
    }
    return (0);
}