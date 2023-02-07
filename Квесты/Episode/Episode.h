#pragma once
#include "Questions/Question.h"
#include "Questions/QuestionTypes.h"

namespace back {
	class Episode
	{
	protected:
		int id;
		int status;
        questUnit::Question* question;
        StatisticalData* sData;
		int sDataLength;
		/// <summary>
		/// инициализирует массив sData и размерность sDataLength на основе id
		/// </summary>
		void setStatisticalData();
		/// <summary>
		/// инициализирует question на основе id
		/// </summary>
		void setFirstStatus();
        /// <summary>
        /// инициализирует question на основе id
        /// </summary>
		void setFirstQuestion();
		/// <summary>
		/// очистить память в куче
		/// </summary>
		void clearMemory();
        /// <summary>
        /// Возвращает id текущего вопроса
        /// </summary>
        int getQuestionId();
	public:
		Episode();
		/// <summary>
		/// Инициализировать новый эпизод
		/// </summary>
		/// <param name="id_">id нового эпизода</param>
		void setNewEpisode(int id_);
        /// <summary>
        /// получить имя активного вопроса
        /// </summary>
		std::string getQuestionName();
		/// <summary>
		/// получить статус эпизода
		/// </summary>
		int getStatus();
		/// <summary>
		/// получить количество вариантов ответа на активный вопрос
		/// </summary>
		int getCountAnswers();
        /// <summary>
		/// получить id эпизода
		/// </summary>
		int getId();
		/// <summary>
		/// обрабатывает полученный ответ и осуществляет переход к следующему вопросу
		/// </summary>
		/// <param name="answer">id ответа</param>
		/// <returns>answer</returns>
		int processAnswer(int answer);
		/// <summary>
		/// получить длину массива статистических данных (количество разнородных данных)
		/// </summary>
		int getStatisticalDataLength();
		/// <summary>
		/// получить структуру с данными об одном измерении с индексом index
		/// </summary>
		/// <param name="index"> элемент массива StatisticalData</param>
        StatisticalData getStatisticalData(int index);
        /// <summary>
        /// получить массив диалогов
        /// </summary>
        std::vector<std::string> getDialogues();
        /// <summary>
        /// получить массив диалогов
        /// </summary>
        std::vector<std::string> getAnswers();
		/// <summary>
		/// получить результаты игры
		/// </summary>
		/// <returns>true - игра выиграна;   false - игра проиграна</returns>
		bool getGameResult();
        /// <summary>
        /// возвращает значение, отвечающее на вопрос "Закончена ли игра?"
        /// </summary>
        /// <returns>true - игра закончена;   false - игра не закончена</returns>
        bool isFinal();
		~Episode();
	};
}