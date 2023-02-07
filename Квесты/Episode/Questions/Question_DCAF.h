#pragma once
#include "Question.h"

namespace questUnit {
    class Question_DCAF : public Question
    {
    public:
        Question_DCAF();
        void processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData) override;
    };
}
