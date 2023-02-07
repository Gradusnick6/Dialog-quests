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
		/// добавляет к полям объекта соответсвующие значения параметров
		/// </summary>
		/// <param name="curAddition">добавочное значение для curCount</param>
		/// <param name="maxAddition">добавочное значение для maxCount</param>
		void changeCount(int curAddition, int maxAddition);
        /// <summary>
        /// true - данные используются в этом эпизоде;
        /// false - данные не актуальны для этого эпизода
        /// </summary>
        bool isRelevant();
	};
}