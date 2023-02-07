#pragma once
#include "Question.h"

namespace questUnit {
    class Question_IFP : public Question
    {
    public:
        Question_IFP();
        void processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData) override;
    };
}
