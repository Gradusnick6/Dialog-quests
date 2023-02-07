#pragma once
#include "Question.h"


void questUnit::Question::setDialoguesList(int size)
{
    std::vector<std::string> dialoguesBuf;
    for (int i = 0; i < size; i++)
        dialoguesBuf.push_back("");
    dialogues = dialoguesBuf;
}

void questUnit::Question::setAnswersList(int size)
{
    std::vector<std::string> answersBuf;
    for (int i = 0; i < size; i++)
        answersBuf.push_back("");
    answers = answersBuf;
}

int questUnit::Question::getIndexForMax(int iSData)
{
    return 2 * iSData;
}

int questUnit::Question::getIndexForCur(int iSData)
{
    return 2 * iSData + 1;
}

int questUnit::Question::correctAnswer(int answer)
{
    if (answer < 1) return 1;
    if (answer > answers.size()) return answers.size();
    return answer;
}

questUnit::Question::Question()
{
    id = ERORR_Q;
    name = "Пасхалка";
    std::vector<std::string> dialoguesBuf;
    dialoguesBuf.push_back("");
    dialoguesBuf.push_back("");
    dialogues = dialoguesBuf;
}

void questUnit::Question::setQuestion(int episode, int number)
{
    id = number;
    if (number == ERORR_Q)
    {
        std::vector<std::string> dialoguesBuf;
        dialoguesBuf.push_back("Он это заметил...");
        dialoguesBuf.push_back("Даааа... И что делать будем?");
        dialogues = dialoguesBuf;
        std::vector<std::string> answersBuf;
        answersBuf.push_back("Получается я выиграл");
        answers = answersBuf;
        return;
    }
    if (number == END) return;

    name = fileReader::FileReader::getQuestionString(episode, number);
    answers = fileReader::FileReader::getAnswersString(episode, number);
}

int questUnit::Question::getCountAnswers() { return answers.size(); }

std::string questUnit::Question::getName() { return name; }

int questUnit::Question::getId() { return id; }

std::vector <std::string> questUnit::Question::getDialogues()
{
    if (dialogues.size() == 0)
        setDialoguesList(2);
    return dialogues;
}

std::vector <std::string> questUnit::Question::getAnswers()
{ 
    if (answers.size() == 0)
        setAnswersList(4);
    return answers; 
}