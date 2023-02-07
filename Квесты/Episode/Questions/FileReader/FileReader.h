#pragma once
#include <iostream>
#include"Database/Database.h"
#include <vector>

#define EOF_WORD "EofWord"

namespace fileReader {
	static class FileReader
	{
    private:
        /// <summary>
        /// возвращает строку-путь к каталогу с файлами directory
        /// </summary>
        /// <param name="directory">- id строки с названием каталога</param>
        static std::string getDirectoryPath(int directory);
        /// <summary>
        /// возвращает число из конструкции "(число)" из str
        /// </summary>
        /// <param name="startIndex">левая граница диапазона в str (включительно)</param>
        /// <param name="endIndex">правая граница диапазона в str (включительно)</param>
        static int getNumber(std::string str, int startIndex, int endIndex);
        /// <summary>
        /// является ли строка началом нового элемента в списке/соответсвует конструкции "(число)"
        /// </summary>
        /// <returns>true - строка соответствует конструкции "(число)"
        /// false - строка не соответствует конструкции "(число)"</returns>
        static bool isNewItem(std::string str);
        /// <summary>
        /// возвращает соответсвует ли строку str структуре firstSimbol.int
        /// </summary>
        /// <param name="firstSimbol">возможные значения: A D</param>
        /// <returns>
        /// true - строка соответсвует структуре;  false - строка не соответсвует структуре;</returns>
        static bool isNewAlternative(std::string str, char firstSimbol);
        /// <summary>
        /// переводит указатель в файле file на элемент в списке под номером number
        /// </summary>
        static void findNumberOnFile(std::ifstream& file, int number);
        /// <summary>
        /// переводит указатель в файле file на ответ под номером answer
        /// </summary>
        static void findAnswerOnQuestion(std::ifstream& file, int answer);
	public:
		/// <summary>
		/// возвращает строку-вопрос
		/// </summary>
        /// <param name="episode"> - id эпизода</param>
        /// <param name="question"> - id вопроса</param>
        static std::string getQuestionString(int episode, int question);
        /// <summary>
        /// возвращает массив строк-диалогов
        /// </summary>
        /// <param name="episode"> - id эпизода</param>
        /// <param name="question"> - id вопроса</param>
        /// <param name="answer"> - id ответа</param>
        /// <param name="countDialogues"> - количество диалогов</param>
        static std::vector<std::string> getDialoguesString(int episode, int question, int answer, int countDialogues);
        /// <summary>
        /// возвращает массив строк-ответов
        /// </summary>
        /// <param name="episode"> - id эпизода</param>
        /// <param name="question"> - id вопроса</param>
        static std::vector<std::string> getAnswersString(int episode, int question);
	};
}