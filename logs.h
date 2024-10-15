#pragma once

#include <Windows.h>
#include <thread>
#include <iostream>
#include <string>



namespace LOGI
{
	enum LOG_TYPE
	{
		INFO,
		WARNING,
		CRITICAL
	};


	void Initialize(LPCWSTR title)
	{
		AllocConsole();

		FILE* ft;
		freopen_s(&ft, "CONOUT$", "w", stdout);

		SetConsoleTitle(title);
	}

	bool Logs(LOG_TYPE type, std::string text)
	{
		
		std::string nText;

		try
		{
			switch (type)
			{
			case LOG_TYPE::INFO:
				nText += "[INFO] > " + text;
				break;
			case LOG_TYPE::WARNING:
				nText += "[WARNING] > " + text;
				break;
			case LOG_TYPE::CRITICAL:
				nText += "[ERROR] > " + text;
				break;
			}

			std::cout << nText << std::endl;
		}
		catch(...) { return false; }
		
		return true;
	}

	void Clear()
	{
		system("cls");
	}

	void Shutdown()
	{
		FreeConsole();
	}
}	