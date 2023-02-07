#pragma once
#include "Question_DCAF.h"

questUnit::Question_DCAF::Question_DCAF() : Question()
{
    setDialoguesList(2);
    setAnswersList(4);
}

void questUnit::Question_DCAF::processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData)
{
    answer = correctAnswer(answer);
    dialogues = fileReader::FileReader::getDialoguesString(DISCUSSION_CUSTOMER_ABOUT_FUNCTION, id, answer, 2);
    switch (id)
    {
    case QUESTION_1:
    {
        nextQuestionId_out = QUESTION_2;
        status_out = answer == ANSWER_1 ? INSPIRED_INTERLOCUTOR : CALM_INTERLOCUTOR;
        return;
    }
    case QUESTION_2:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_3;
            status_out = CALM_INTERLOCUTOR;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_5;
                status_out = EVIL_INTERLOCUTOR;
                sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_5;
                    status_out = INSPIRED_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_4;
                        status_out = INTERROGATIVE_INTERLOCUTOR;
                    }
        sData[getIndexForMax(FEATURE_COUNT)] = 1;
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
        return;
    }
    case QUESTION_3:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_5;
            status_out = EVIL_INTERLOCUTOR;
            sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_5;
                status_out = EVIL_INTERLOCUTOR;
                sData[getIndexForCur(FEATURE_COUNT)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_5;
                    status_out = CALM_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_5;
                        status_out = CALM_INTERLOCUTOR;
                    }
        return;
    }
    case QUESTION_4:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_5;
            status_out = EVIL_INTERLOCUTOR;
            sData[getIndexForCur(FEATURE_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_5;
                status_out = CALM_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_5;
                    status_out = EVIL_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_5;
                        status_out = EVIL_INTERLOCUTOR;
                        sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
                    }
        return;
    }
    case QUESTION_5:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_6;
            status_out = CALM_INTERLOCUTOR;
            sData[getIndexForCur(FEATURE_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_6;
                status_out = INSPIRED_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_7;
                    status_out = INSPIRED_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_7;
                        status_out = EVIL_INTERLOCUTOR;
                        sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
                    }
        sData[getIndexForMax(FEATURE_COUNT)] = 1;
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
        return;
    }
    case QUESTION_6:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_9;
            status_out = CALM_INTERLOCUTOR;
            sData[getIndexForCur(FEATURE_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_9;
                status_out = CALM_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_9;
                    status_out = INSPIRED_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_9;
                        status_out = EVIL_INTERLOCUTOR;
                        sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
                    }
        sData[getIndexForMax(FEATURE_COUNT)] = 1;
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
        return;
    }
    case QUESTION_7:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_8;
            status_out = EVIL_INTERLOCUTOR;
            sData[getIndexForCur(FEATURE_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_8;
                status_out = CALM_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_8;
                    status_out = INSPIRED_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_8;
                        status_out = EVIL_INTERLOCUTOR;
                        sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
                    }
        sData[getIndexForMax(FEATURE_COUNT)] = 1;
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
        return;
    }
    case QUESTION_8:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_10;
            status_out = EVIL_INTERLOCUTOR;
            sData[getIndexForCur(FEATURE_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_10;
                status_out = CALM_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_10;
                    status_out = EVIL_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_10;
                        status_out = EVIL_INTERLOCUTOR;
                        sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
                    }
        sData[getIndexForMax(FEATURE_COUNT)] = 1;
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
        return;
    }
    case QUESTION_9:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_10;
            status_out = EVIL_INTERLOCUTOR;
            sData[getIndexForCur(FEATURE_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_10;
                status_out = CALM_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_10;
                    status_out = CALM_INTERLOCUTOR;
                    sData[getIndexForCur(FEATURE_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_10;
                        status_out = EVIL_INTERLOCUTOR;
                        sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
                    }
        sData[getIndexForMax(FEATURE_COUNT)] = 1;
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
        return;
    }
    case QUESTION_10:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = END;
            status_out = CALM_INTERLOCUTOR;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = END;
                status_out = EVIL_INTERLOCUTOR;
                sData[getIndexForCur(REASONS_TO_DISMISS)] = 1;
            }
        sData[getIndexForMax(REASONS_TO_DISMISS)] = 1;
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