#pragma once
#include <iostream>
#include <vector>

namespace back 
{
    /// <summary>
    /// ����������� string � wstring
    /// </summary>
    std::wstring getWstring(std::string str);
    /// <summary>
    /// ���������� ������ wstring ���������������� �� string
    /// </summary>
    std::vector<std::wstring> convertVectorToWstring(std::vector<std::string>& array);
}