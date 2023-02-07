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
        /// ���������� ������-���� � �������� � ������� directory
        /// </summary>
        /// <param name="directory">- id ������ � ��������� ��������</param>
        static std::string getDirectoryPath(int directory);
        /// <summary>
        /// ���������� ����� �� ����������� "(�����)" �� str
        /// </summary>
        /// <param name="startIndex">����� ������� ��������� � str (������������)</param>
        /// <param name="endIndex">������ ������� ��������� � str (������������)</param>
        static int getNumber(std::string str, int startIndex, int endIndex);
        /// <summary>
        /// �������� �� ������ ������� ������ �������� � ������/������������ ����������� "(�����)"
        /// </summary>
        /// <returns>true - ������ ������������� ����������� "(�����)"
        /// false - ������ �� ������������� ����������� "(�����)"</returns>
        static bool isNewItem(std::string str);
        /// <summary>
        /// ���������� ������������ �� ������ str ��������� firstSimbol.int
        /// </summary>
        /// <param name="firstSimbol">��������� ��������: A D</param>
        /// <returns>
        /// true - ������ ������������ ���������;  false - ������ �� ������������ ���������;</returns>
        static bool isNewAlternative(std::string str, char firstSimbol);
        /// <summary>
        /// ��������� ��������� � ����� file �� ������� � ������ ��� ������� number
        /// </summary>
        static void findNumberOnFile(std::ifstream& file, int number);
        /// <summary>
        /// ��������� ��������� � ����� file �� ����� ��� ������� answer
        /// </summary>
        static void findAnswerOnQuestion(std::ifstream& file, int answer);
	public:
		/// <summary>
		/// ���������� ������-������
		/// </summary>
        /// <param name="episode"> - id �������</param>
        /// <param name="question"> - id �������</param>
        static std::string getQuestionString(int episode, int question);
        /// <summary>
        /// ���������� ������ �����-��������
        /// </summary>
        /// <param name="episode"> - id �������</param>
        /// <param name="question"> - id �������</param>
        /// <param name="answer"> - id ������</param>
        /// <param name="countDialogues"> - ���������� ��������</param>
        static std::vector<std::string> getDialoguesString(int episode, int question, int answer, int countDialogues);
        /// <summary>
        /// ���������� ������ �����-�������
        /// </summary>
        /// <param name="episode"> - id �������</param>
        /// <param name="question"> - id �������</param>
        static std::vector<std::string> getAnswersString(int episode, int question);
	};
}