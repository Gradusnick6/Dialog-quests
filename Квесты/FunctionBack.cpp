#include <cstdlib>
#include "FunctionBack.h"

#define _CRT_SECURE_NO_WARNINGS 1

std::wstring back::getWstring(std::string str)
{
    const char* c = str.c_str();
    const size_t cSize = str.size() + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);
    std::wstring w_string(wc);
    delete[] wc;
    return w_string;
};

std::vector<std::wstring> back::convertVectorToWstring(std::vector<std::string>& array)
{
    std::vector<std::wstring> buf;
    for (int i = 0; i < array.size(); i++)
        buf.push_back(getWstring(array[i]));
    return buf;
}