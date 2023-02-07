#pragma once
#include <iostream>
#include <vector>

namespace back 
{
    /// <summary>
    /// конвертация string в wstring
    /// </summary>
    std::wstring getWstring(std::string str);
    /// <summary>
    /// возвращает вектор wstring конвертированный из string
    /// </summary>
    std::vector<std::wstring> convertVectorToWstring(std::vector<std::string>& array);
}