#include <iostream>
#include "Episode/Episode.h"

void printDialogues(back::Episode& episode)
{
    std::cout << "________________________________________________________" << std::endl;
    std::cout << "Вы сказали:  " << episode.getDialogues()[0] << std::endl;
    std::cout << "Вам сказали:  " << episode.getDialogues()[1] << std::endl;
    std::cout << "________________________________________________________" << std::endl;
}

void printStatisticalData(back::Episode& episode)
{
    back::StatisticalData temp;
    for (int i = 0; i < episode.getStatisticalDataLength(); i++)
    {
        temp = episode.getStatisticalData(i);
        std::cout << temp.name << temp.curCount << "/" << temp.maxCount << std::endl;
    }
}

std::string interpretationResult(bool result)
{
    return result ? "Победа!" : "Поражение :(";
}



void runEpisode(int episodeId, std::vector<std::string> textSData)
{
    setlocale(LC_ALL, "rus");
    back::Episode episode;
    episode.setNewEpisode(episodeId);
    while (!episode.isFinal())
    {
        int answer = 0;
        std::cout << "Эпизод  " << episode.getId() << std::endl;
        std::cout << "Статус  " << episode.getStatus() << std::endl;
        printStatisticalData(episode);
        printDialogues(episode);
        std::cout << "Формулировка вопроса:  " << episode.getQuestionName() << std::endl;
        std::cout << std::endl << "Возможные ответы:  ";
        for (int i = 0; i < episode.getCountAnswers(); i++)
            std::cout << std::endl << i + 1 << ") " << episode.getAnswers()[i];
        std::cout << std::endl << std::endl << "Введите ответ: ";
        std::cin >> answer;
        episode.processAnswer(answer);
        std::cout << std::endl << "////////////////////////////////////////////////////////////////////////////";
        std::cout << std::endl << "____________________________________________________________________________" << std::endl;
    }
    printDialogues(episode);
    printStatisticalData(episode);
    std::cout << "Результат игры:  " << interpretationResult(episode.getGameResult()) << std::endl << std::endl;
}

int main()
{
    std::vector<std::string> textSData;
    int episodeId = INTERVIEW_FOR_PROGRAMMER;

    if (episodeId == DISCUSSION_TEAM_LEADER_ABOUT_BUG)
    {
        textSData.push_back("Количество багов: ");
        textSData.push_back("Количество багов для стажера: ");
    }
    if (episodeId == DISCUSSION_CUSTOMER_ABOUT_FUNCTION)
    {
        textSData.push_back("Нужно реализовать фич: ");
        textSData.push_back("Желание уволить: ");
    }
    if (episodeId == INTERVIEW_FOR_PROGRAMMER)
    {
        textSData.push_back("Желание взять на работу: ");
    }

    runEpisode(episodeId, textSData);
}