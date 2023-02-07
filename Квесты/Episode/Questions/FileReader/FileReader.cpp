#pragma once
#include "FileReader.h"
#include <fstream>
#include <string>

std::string fileReader::FileReader::getDirectoryPath(int episode)
{
    switch (episode)
    {
    case DISCUSSION_TEAM_LEADER_ABOUT_BUG: return "Data\\DTLAB\\";
    case DISCUSSION_CUSTOMER_ABOUT_FUNCTION: return "Data\\DCAF\\";
    case INTERVIEW_FOR_PROGRAMMER: return "Data\\IFP\\";
    default: return "";
    }
}

int fileReader::FileReader::getNumber(std::string str, int startIndex, int endIndex)
{
    std::string buf = "";
    for (int i = startIndex; i <= endIndex; i++)
        buf.push_back(str[i]);
    int result = -1;
    result = std::stoi(buf);
    return result;
}

bool fileReader::FileReader::isNewItem(std::string str)
{
    if (str.length() < 3) return false;

    if (str[0] != '(' || str[str.length() - 1] != ')')
        return false;

    for (int i = 1; i < (int)str.length() - 1; i++)
    {
        if ((int)str[i] < '0' || (int)str[i] > '9')
            return false;
    }
    return true;
}

bool fileReader::FileReader::isNewAlternative(std::string str, char firstSimbol)
{
    if (str.length() < 3) return false;

    if (str[0] != firstSimbol || str[1] != '.')
        return false;

    for (int i = 2; i < (int)str.length(); i++)
    {
        if ((int)str[i] < '0' || (int)str[i] > '9')
            return false;
    }
    return true;
}

void fileReader::FileReader::findNumberOnFile(std::ifstream& file, int number)
{
    file.seekg(0, std::ios::beg);
    std::string pointersShifter;
    do {
        do
        {
            file >> pointersShifter;
            if (pointersShifter == EOF_WORD) return;

        } while (!isNewItem(pointersShifter));
    } while (getNumber(pointersShifter, 1, pointersShifter.length() - 2) != number);
}

void fileReader::FileReader::findAnswerOnQuestion(std::ifstream& file, int answer)
{
    std::string pointersShifter;
    do {
        do
        {
            file >> pointersShifter;
            if (pointersShifter == EOF_WORD) return;

        } while (!isNewAlternative(pointersShifter, 'A'));
    } while (getNumber(pointersShifter, 2, pointersShifter.length() - 1) != answer);
}

std::string fileReader::FileReader::getQuestionString(int episode, int question)
{
	std::ifstream file(getDirectoryPath(episode) + "Questions.txt");
    if (!file) return "";

    std::string result = "";
    findNumberOnFile(file, question);

	std::string buf;
	do
	{
		file >> buf;

        if (buf == EOF_WORD || isNewItem(buf)) break;

        result += buf;
        result.push_back(' ');
	} while (true);

    file.close();
    return result;
}

std::vector<std::string> fileReader::FileReader::getDialoguesString(int episode, int question, int answer, int countDialogues)
{
    std::vector<std::string> result;
    for (int i = 0; i < countDialogues; i++)
        result.push_back("");

    std::ifstream file(getDirectoryPath(episode) + "Dialogues.txt");
    if (!file)
        return result;

    findNumberOnFile(file, question);
    findAnswerOnQuestion(file, answer);

    int curPhrase = -1;
    std::string buf;
    do
    {
        file >> buf;

        if (isNewAlternative(buf, 'D'))
        {
            curPhrase++;
            continue;
        }
        if (buf == EOF_WORD || isNewItem(buf) || isNewAlternative(buf, 'A')) break;

        result[curPhrase] += buf;
        result[curPhrase].push_back(' ');
    } while (true);

    file.close();
    return result;
}

std::vector<std::string> fileReader::FileReader::getAnswersString(int episode, int question)
{
    std::vector<std::string> result;

    std::ifstream file(getDirectoryPath(episode) + "Answers.txt");
    if (!file)
        return result;

    findNumberOnFile(file, question);
    std::string buf, ptr;
    file >> ptr;
    do
    {
        file >> ptr;

        if (isNewAlternative(ptr, 'A'))
        {
            result.push_back(buf);
            buf = "";
            continue;
        }
        if (isNewItem(ptr) || ptr == EOF_WORD)
        {
            result.push_back(buf);
            break;
        }

        buf += ptr;
        buf.push_back(' ');

    } while (true);

    file.close();
    return result;
}