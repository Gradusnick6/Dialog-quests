#pragma once
#include "Episode.h"

void back::Episode::setStatisticalData()
{
	switch (id)
	{
	case DISCUSSION_TEAM_LEADER_ABOUT_BUG:
	{
		sDataLength = 2;
		sData = new StatisticalData[sDataLength]();
        sData[BUG_COUNT].setName("Количество багов: ");
        sData[BUG_FOR_INTERN].setName("Количество багов для стажера: ");
		return;
	}
    case DISCUSSION_CUSTOMER_ABOUT_FUNCTION:
    {
        sDataLength = 2;
        sData = new StatisticalData[sDataLength]();
        sData[FEATURE_COUNT].setName("Нужно реализовать фич: ");
        sData[REASONS_TO_DISMISS].setName("Желание уволить: ");
        return;
    }
    case INTERVIEW_FOR_PROGRAMMER: 
    {
        sDataLength = 1;
        sData = new StatisticalData[sDataLength]();
        sData[DESIRE_HIRE].setName("Желание взять на работу: ");
        return;
    }
	default:
		sData = nullptr;
	}
}

void back::Episode::setFirstQuestion()
{
    switch (id)
    {
    case DISCUSSION_TEAM_LEADER_ABOUT_BUG: question = new questUnit::Question_DTLAB(); break;
    case DISCUSSION_CUSTOMER_ABOUT_FUNCTION: question = new questUnit::Question_DCAF(); break;
    case INTERVIEW_FOR_PROGRAMMER: question = new questUnit::Question_IFP(); break;

    default:
        question->setQuestion(ERORR_E, ERORR_Q);
    }
    question->setQuestion(id, QUESTION_1);
}

void back::Episode::setFirstStatus()
{
	switch (id)
	{
	case DISCUSSION_TEAM_LEADER_ABOUT_BUG: { status = CALM_INTERLOCUTOR; return; }
    case DISCUSSION_CUSTOMER_ABOUT_FUNCTION: { status = CALM_INTERLOCUTOR; return; }
    case INTERVIEW_FOR_PROGRAMMER: { status = CALM_INTERLOCUTOR; return; }
	default:
	{
        status = INTERROGATIVE_INTERLOCUTOR;
		return;
	}
	}
}

void back::Episode::clearMemory()
{
	if (sData != nullptr)
		delete[] sData;
    sData = nullptr;
	if (question == nullptr)
		delete question;
    question = nullptr;
}

int back::Episode::getQuestionId() { return question->getId(); }

back::Episode::Episode()
{
	id = ERORR_E;
	status = 0;
	sDataLength = 0;
	sData = nullptr;
	question = nullptr;
}

void back::Episode::setNewEpisode(int id_)
{
	clearMemory();
	id = id_;
	setFirstStatus();
	setFirstQuestion();
	setStatisticalData();
}

std::string back::Episode::getQuestionName() { return question->getName(); }

int back::Episode::getStatus() { return status; }

int back::Episode::getCountAnswers() { return question->getCountAnswers(); }

int back::Episode::getId() { return id; }

int back::Episode::processAnswer(int answer)
{
    int nextQ, newStatus;
    int* newSData = new int[sDataLength * 2]();

    question->processAnswer(answer, sDataLength, nextQ, newStatus, newSData);
    status = newStatus;
    question->setQuestion(id, nextQ);

    for (int i = 0; i < sDataLength * 2; i += 2)
        sData[i / 2].changeCount(newSData[i + 1], newSData[i]);
    delete[] newSData;

    return answer;
}

int back::Episode::getStatisticalDataLength() { return sDataLength; }

back::StatisticalData back::Episode::getStatisticalData(int index)
{
    if (sData != nullptr && (index < sDataLength && index >= 0))
        return sData[index];
    return StatisticalData();
}

std::vector<std::string> back::Episode::getDialogues() { return question->getDialogues(); }

std::vector<std::string> back::Episode::getAnswers() { return question->getAnswers(); }

bool back::Episode::getGameResult()
{
    if (getQuestionId() == ERORR_Q)
        return true;
    switch (id)
    {
    case DISCUSSION_TEAM_LEADER_ABOUT_BUG:
    {
        int score_bugs = getStatisticalData(BUG_COUNT).curCount * 2;
        int score_bugsForIntern = getStatisticalData(BUG_FOR_INTERN).curCount;
        return score_bugs + score_bugsForIntern <= 4;
    }
    case DISCUSSION_CUSTOMER_ABOUT_FUNCTION:
    {
        int score_features = getStatisticalData(FEATURE_COUNT).curCount;
        int score_rasonsToDismiss = getStatisticalData(REASONS_TO_DISMISS).curCount * 2;
        return score_features + score_rasonsToDismiss <= 5;
    }
    case INTERVIEW_FOR_PROGRAMMER: 
        return getStatisticalData(DESIRE_HIRE).curCount > 5;
    default:
        return true;
    }
}

bool back::Episode::isFinal() { return getQuestionId() == END || getQuestionId() == ERORR_Q; }

back::Episode::~Episode() {	clearMemory(); }