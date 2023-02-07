#pragma once
#include "StatisticalData.h"

back::StatisticalData::StatisticalData()
{
	maxCount = 0;
	curCount = 0;
    name = "";
}

void back::StatisticalData::setName(std::string name_){ name = name_; }

void back::StatisticalData::changeCount(int curAddition = 1, int maxAddition = 1)
{
	curCount += curAddition;
	maxCount += maxAddition;
}

bool back::StatisticalData::isRelevant() { return name != ""; }