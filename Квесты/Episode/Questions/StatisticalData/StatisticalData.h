#pragma once
#include <iostream>

namespace back
{
	class StatisticalData
	{
	public:
		int maxCount;
		int curCount;
        std::string name;
		StatisticalData();
        void setName(std::string name_);
		/// <summary>
		/// ��������� � ����� ������� �������������� �������� ����������
		/// </summary>
		/// <param name="curAddition">���������� �������� ��� curCount</param>
		/// <param name="maxAddition">���������� �������� ��� maxCount</param>
		void changeCount(int curAddition, int maxAddition);
        /// <summary>
        /// true - ������ ������������ � ���� �������;
        /// false - ������ �� ��������� ��� ����� �������
        /// </summary>
        bool isRelevant();
	};
}