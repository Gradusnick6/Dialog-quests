#pragma once
#include "Question.h"

namespace questUnit {
	class Question_DTLAB : public Question
	{
	public:
        Question_DTLAB();
		void processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData) override;
	};
}