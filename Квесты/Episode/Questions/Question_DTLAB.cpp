#pragma once
#include "Question_DTLAB.h"

questUnit::Question_DTLAB::Question_DTLAB() : Question()
{
    setDialoguesList(2);
    setAnswersList(4);
}

void questUnit::Question_DTLAB::processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData)
{
    answer = correctAnswer(answer);
    dialogues = fileReader::FileReader::getDialoguesString(DISCUSSION_TEAM_LEADER_ABOUT_BUG, id, answer, 2);
    switch (id)
    {
    case QUESTION_1:
    {
        nextQuestionId_out = QUESTION_2;
        status_out = answer == ANSWER_1 ? EVIL_INTERLOCUTOR : CALM_INTERLOCUTOR;
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
            if (answer == ANSWER_2 || answer == ANSWER_4)
            {
                nextQuestionId_out = QUESTION_4;
                status_out = EVIL_INTERLOCUTOR;
                sData[getIndexForCur(BUG_COUNT)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_4;
                    status_out = CALM_INTERLOCUTOR;
                    sData[getIndexForCur(BUG_FOR_INTERN)] = 1;
                }
        sData[getIndexForMax(BUG_COUNT)] = 1; 
        sData[getIndexForMax(BUG_FOR_INTERN)] = 1;
        return;
    }
    case QUESTION_3:
    {
        nextQuestionId_out = QUESTION_4;
        status_out = answer != ANSWER_3 ? EVIL_INTERLOCUTOR : CALM_INTERLOCUTOR;
        sData[getIndexForCur(BUG_COUNT)] = answer != ANSWER_3 ? 1 : 0;
        return;
    }
    case QUESTION_4:
    {
        if (answer == ANSWER_1 || answer == ANSWER_3)
        {
            nextQuestionId_out = QUESTION_5;
            status_out = EVIL_INTERLOCUTOR;
            sData[getIndexForCur(BUG_COUNT)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_5;
                status_out = INTERROGATIVE_INTERLOCUTOR;
            }
            else
                if (answer == ANSWER_4)
                {
                    nextQuestionId_out = QUESTION_5;
                    status_out = CALM_INTERLOCUTOR;
                    sData[getIndexForCur(BUG_FOR_INTERN)] = 1;
                }
        sData[getIndexForMax(BUG_COUNT)] = 1; 
        sData[getIndexForMax(BUG_FOR_INTERN)] = 1;
        return;
    }
    case QUESTION_5:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_7;
            status_out = CALM_INTERLOCUTOR;
            sData[getIndexForCur(BUG_FOR_INTERN)] = 1;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_7;
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(BUG_COUNT)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_7;
                    status_out = INTERROGATIVE_INTERLOCUTOR;
                    sData[getIndexForCur(BUG_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_6;
                        status_out = INTERROGATIVE_INTERLOCUTOR;
                    }
        sData[getIndexForMax(BUG_COUNT)] = 1;
        sData[getIndexForMax(BUG_FOR_INTERN)] = 1;
        return;
    }
    case QUESTION_6:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_7;
            status_out = CALM_INTERLOCUTOR;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_7;
                status_out = INTERROGATIVE_INTERLOCUTOR;
                sData[getIndexForCur(BUG_COUNT)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    nextQuestionId_out = QUESTION_7;
                    status_out = EVIL_INTERLOCUTOR;
                    sData[getIndexForCur(BUG_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        nextQuestionId_out = QUESTION_7;
                        status_out = CALM_INTERLOCUTOR;
                    }
        return;
    }
    case QUESTION_7:
    {
        if (answer == ANSWER_1)
        {
            nextQuestionId_out = QUESTION_8;
            status_out = INTERROGATIVE_INTERLOCUTOR;
        }
        else
            if (answer == ANSWER_2)
            {
                nextQuestionId_out = QUESTION_8;
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(BUG_FOR_INTERN)] = 1;
            }
            else
                if (answer == ANSWER_3 || answer == ANSWER_4)
                {
                    nextQuestionId_out = QUESTION_8;
                    status_out = INTERROGATIVE_INTERLOCUTOR;
                    sData[getIndexForCur(BUG_COUNT)] = 1;
                }
        sData[getIndexForMax(BUG_COUNT)] = 1;
        sData[getIndexForMax(BUG_FOR_INTERN)] = 1;
        return;
    }
    case QUESTION_8:
    {
        if (answer == ANSWER_1)
            status_out = INTERROGATIVE_INTERLOCUTOR;
        else
            if (answer == ANSWER_2)
            {
                status_out = CALM_INTERLOCUTOR;
                sData[getIndexForCur(BUG_COUNT)] = 1;
            }
            else
                if (answer == ANSWER_3)
                {
                    status_out = INTERROGATIVE_INTERLOCUTOR;
                    sData[getIndexForCur(BUG_COUNT)] = 1;
                }
                else
                    if (answer == ANSWER_4)
                    {
                        status_out = CALM_INTERLOCUTOR;
                        sData[getIndexForCur(BUG_FOR_INTERN)] = 1;
                    }
        nextQuestionId_out = QUESTION_9;
        sData[getIndexForMax(BUG_COUNT)] = 1;
        sData[getIndexForMax(BUG_FOR_INTERN)] = 1;
        return;
    }
    case QUESTION_9:
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