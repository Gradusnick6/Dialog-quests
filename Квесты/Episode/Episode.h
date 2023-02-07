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
		/// �������������� ������ sData � ����������� sDataLength �� ������ id
		/// </summary>
		void setStatisticalData();
		/// <summary>
		/// �������������� question �� ������ id
		/// </summary>
		void setFirstStatus();
        /// <summary>
        /// �������������� question �� ������ id
        /// </summary>
		void setFirstQuestion();
		/// <summary>
		/// �������� ������ � ����
		/// </summary>
		void clearMemory();
        /// <summary>
        /// ���������� id �������� �������
        /// </summary>
        int getQuestionId();
	public:
		Episode();
		/// <summary>
		/// ���������������� ����� ������
		/// </summary>
		/// <param name="id_">id ������ �������</param>
		void setNewEpisode(int id_);
        /// <summary>
        /// �������� ��� ��������� �������
        /// </summary>
		std::string getQuestionName();
		/// <summary>
		/// �������� ������ �������
		/// </summary>
		int getStatus();
		/// <summary>
		/// �������� ���������� ��������� ������ �� �������� ������
		/// </summary>
		int getCountAnswers();
        /// <summary>
		/// �������� id �������
		/// </summary>
		int getId();
		/// <summary>
		/// ������������ ���������� ����� � ������������ ������� � ���������� �������
		/// </summary>
		/// <param name="answer">id ������</param>
		/// <returns>answer</returns>
		int processAnswer(int answer);
		/// <summary>
		/// �������� ����� ������� �������������� ������ (���������� ����������� ������)
		/// </summary>
		int getStatisticalDataLength();
		/// <summary>
		/// �������� ��������� � ������� �� ����� ��������� � �������� index
		/// </summary>
		/// <param name="index"> ������� ������� StatisticalData</param>
        StatisticalData getStatisticalData(int index);
        /// <summary>
        /// �������� ������ ��������
        /// </summary>
        std::vector<std::string> getDialogues();
        /// <summary>
        /// �������� ������ ��������
        /// </summary>
        std::vector<std::string> getAnswers();
		/// <summary>
		/// �������� ���������� ����
		/// </summary>
		/// <returns>true - ���� ��������;   false - ���� ���������</returns>
		bool getGameResult();
        /// <summary>
        /// ���������� ��������, ���������� �� ������ "��������� �� ����?"
        /// </summary>
        /// <returns>true - ���� ���������;   false - ���� �� ���������</returns>
        bool isFinal();
		~Episode();
	};
}