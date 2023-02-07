#pragma once
#include "Question_IFP.h"

questUnit::Question_IFP::Question_IFP() : Question()
{
    setDialoguesList(2);
    setAnswersList(4);
}

void questUnit::Question_IFP::processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData)
{
    answer = correctAnswer(answer);
    dialogues = fileReader::FileReader::getDialoguesString(INTERVIEW_FOR_PROGRAMMER, id, answer, 2);
    switch (id)
    {
    case QUESTION_1:
    {
        nextQuestionId_out = QUESTION_2;
        status_out = answer == ANSWER_1 ? DISPLEASED_INTERLOCUTOR : CALM_INTERLOCUTOR;
        return;
    }
    case QUESTION_2:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_3;
            status_out = INTERROGATIVE_INTERLOCUTOR;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_4;
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_3;
                    status_out = INTERROGATIVE_INTERLOCUTOR;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_4;
                        status_out = CALM_INTERLOCUTOR;
                    }
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_3:
    {
        if (answer == ANSWER_1)
        {
            status_out = CALM_INTERLOCUTOR;
            sData[getIndexForCur(DESIRE_HIRE)] = 1;
        }
        else
            if (answer == ANSWER_2)
                status_out = DISPLEASED_INTERLOCUTOR;
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                    status_out = INTERROGATIVE_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_4;
        return;
    }
    case QUESTION_4:
    {
        if (answer == ANSWER_1)
            status_out = INTERROGATIVE_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                    status_out = DISPLEASED_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_5;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_5:
    {
        if (answer == ANSWER_2)
        {
            status_out = CALM_INTERLOCUTOR;
            sData[getIndexForCur(DESIRE_HIRE)] = 1;
        }
        else
            if (answer == ANSWER_1 || answer == ANSWER_3)
                status_out = INTERROGATIVE_INTERLOCUTOR;
            else
                if (answer == ANSWER_4)
                    status_out = CALM_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_6;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_6:
    {
        if (answer == ANSWER_1)
            status_out = INTERROGATIVE_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                    status_out = DISPLEASED_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_7;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_7:
    {
        if (answer == ANSWER_1)
            status_out = INTERROGATIVE_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                    status_out = DISPLEASED_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_8;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_8:
    {
        if (answer == ANSWER_1)
            status_out = DISPLEASED_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                    status_out = INTERROGATIVE_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_9;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_9:
    {
        if (answer == ANSWER_1 || answer == ANSWER_3)
            status_out = CALM_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
                if (answer == ANSWER_4)
                    status_out = DISPLEASED_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_10;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_10:
    {
        if (answer == ANSWER_1)
            status_out = DISPLEASED_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(DESIRE_HIRE)] = 1;
            }
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                    status_out = CALM_INTERLOCUTOR;

        nextQuestionId_out = QUESTION_11;
        sData[getIndexForMax(DESIRE_HIRE)] = 1;
        return;
    }
    case QUESTION_11:
    {
        nextQuestionId_out = END;
        status_out = CALM_INTERLOCUTOR;
        return;
    }
    default:
    {
        nextQuestionId_out = ERORR_Q;
        status_out = ERORR_S;
        return;
    }
    }
}