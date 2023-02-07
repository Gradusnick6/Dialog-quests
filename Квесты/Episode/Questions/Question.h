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
        /// ��������� ������ �������� ������� ��������
        /// </summary>
        /// <param name="size">������ �������</param>
        void setDialoguesList(int size);
        /// <summary>
        /// ��������� ������ ������� ������� ��������
        /// </summary>
        /// <param name="size">������ �������</param>
        void setAnswersList(int size);
        /// <summary>
        /// ���������� ������ ��� ������������� �������� � ���������� ��� ��������� � ����� �������
        /// </summary>
        /// <param name="iSData">������ �������� � ��������� StatisticalData</param>
        int getIndexForMax(int iSData);
        /// <summary>
        /// ���������� ������ ��� �������� �������� � ���������� ��� ��������� � ����� �������
        /// </summary>
        /// <param name="iSData">������ �������� � ��������� StatisticalData</param>
        int getIndexForCur(int iSData);
        /// <summary>
        /// ���������� ����������������� �����, ���� ��������� ����� ���������� ����������. ����� ���������� answer
        /// </summary>
        int correctAnswer(int answer);
	public:
		Question();
        /// <summary>
        /// ���������������� ���� �������
        /// </summary>
        /// <param name="episode">- id �������</param>
        /// <param name="number">- id �������</param>
        void setQuestion(int episode, int number);
		/// <summary>
		/// ������������ ���������� ����� answer
		/// </summary>
		/// <param name="answer">id ����������� ������</param>
		/// <param name="sDataSize">������ ������� StatisticalData � �������</param>
		/// <param name="nextQuestionId_out">id ���������� ������� (������������ ��������)</param>
		/// <param name="status_out">id ������ ������� (������������ ��������)</param>
		/// <param name="sData">��������� � �������������� ������ ������� (������������ ��������). 
		/// ������ ������� - maxCount
		/// �������� ������� - curCount</param>
		virtual void processAnswer(int answer, int sDataSize, int& nextQuestionId_out, int& status_out, int* sData) = 0;
		/// <summary>
		/// ���������� ���������� ��������� ������ �� ������
		/// </summary>
		int getCountAnswers();
		/// <summary>
		/// ���������� ������������ �������
		/// </summary>
		std::string getName();
        /// <summary>
        /// ���������� id �������� �������
        /// </summary>
        int getId();
        /// <summary>
        /// �������� ������ ��������
        /// </summary>
        std::vector <std::string> getDialogues();
        /// <summary>
        /// �������� ������ ��������
        /// </summary>
        std::vector <std::string> getAnswers();
	};
}