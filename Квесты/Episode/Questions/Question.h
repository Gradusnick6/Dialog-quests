#pragma once
#include "FileReader/FileReader.h"
#include "StatisticalData\StatisticalData.h"

namespace questUnit {
	class Question
	{
	protected:
		int id;
        std::string name;
        std::vector <std::string> dialogues;
        std::vector <std::string> answers;
        /// <summary>
        /// заполняет вектор диалогов пустыми строками
        /// </summary>
        /// <param name="size">размер массива</param>
        void setDialoguesList(int size);
        /// <summary>
        /// заполняет вектор ответов пустыми строками
        /// </summary>
        /// <param name="size">размер массива</param>
        void setAnswersList(int size);
        /// <summary>
        /// Возвращает индекс для максимального значения в статистике при обработке в общем массиве
        /// </summary>
        /// <param name="iSData">индекс элемента в структуре StatisticalData</param>
        int getIndexForMax(int iSData);
        /// <summary>
        /// Возвращает индекс для текущего значения в статистике при обработке в общем массиве
        /// </summary>
        /// <param name="iSData">индекс элемента в структуре StatisticalData</param>
        int getIndexForCur(int iSData);
        /// <summary>
        /// возвращает скорректированный ответ, если введенный ответ невозможно обработать. Иначе возвращает answer
        /// </summary>
        int correctAnswer(int answer);
	public:
		Question();
        /// <summary>
        /// инициализировать поля объекта
        /// </summary>
        /// <param name="episode">- id эпизода</param>
        /// <param name="number">- id вопроса</param>
        void setQuestion(int episode, int number);
		/// <summary>
		/// обрабатывает полученный ответ answer
		/// </summary>
		/// <param name="answer">id полученного ответа</param>
		/// <param name="sDataSize">размер массива StatisticalData в эпизоде</param>
		/// <param name="nextQuestionId_out">id следующего вопроса (возвращаемое значение)</param>
		/// <param name="status_out">id нового статуса (возвращаемое значение)</param>
		/// <param name="sData">изменения в статистических данных эпизода (возвращаемое значение). 
		/// Четные индексы - maxCount
		/// Нечетные индексы - curCount</param>
		virtual void processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData) = 0;
		/// <summary>
		/// возвращает количество вариантов ответа на вопрос
		/// </summary>
		int getCountAnswers();
		/// <summary>
		/// возвращает формулировку вопроса
		/// </summary>
		std::string getName();
        /// <summary>
        /// возвращает id текущего вопроса
        /// </summary>
        int getId();
        /// <summary>
        /// получить массив диалогов
        /// </summary>
        std::vector <std::string> getDialogues();
        /// <summary>
        /// получить массив вопросов
        /// </summary>
        std::vector <std::string> getAnswers();
	};
}