#include "logfile.hpp"

logfile::logfile()
{
	//define the file
	fopen_s(&log, logName, "w");

	//check file stream
	if (log == NULL)
	{
		MessageBox(NULL, "Log file initialization failed", "Error", MB_OK | MB_ICONERROR);
		return;
	}
	
	//make html header
	fprintf_s(log, "<html><head><title>LOG</title></head><body style=\"background-color:#2a2a2a; font-family:Consolas; color:lightgray\">");
	fprintf_s(log, "<h1 style=\"font-size:42px;\">Log file</h1>");
#ifdef _DEBUG
	fprintf_s(log, "<h1 style=\"font-size:40px;\">Build: Debug</h1>");
#else
	fprintf_s(log, "<h1 style=\"font-size:40px;\">Build: Release</h1>");
#endif
	fprintf_s(log, "<hr/>");

	//close and open log in append mode
	fclose(log);
	fopen_s(&log, logName, "a");
}

logfile::~logfile()
{
	//write html bottom
	fprintf_s(log, "</body></html>");

	//close log after program shutdown
	fclose(log);
}

void logfile::writeToLog(const char* text)
{
	writeToLog(text, log_color::DEFAULT);
}

void logfile::writeToLog(const char* text, log_color color)
{
	writeToLog(text, color, false);
}

void logfile::writeToLog(const char* text, log_color color, bool critical)
{
	//check whether new text equals last text
	if (lastString._Equal(text))
	{
		//it is so higher the number this string got written to the log
		timesLastStringWritten++;

		//check whether the string got written to the log to many times
		if (timesLastStringWritten > 2)
		{
			//check if this message was already written
			if (!writeLock)
			{
				//if not write message to log that a string was limited to a certain amount of times
				fprintf_s(log, "<p style=\"color:#FF0000;\">The following string has been limited due to too frequently usage: %s</p><br/>", text);

				//force logfile to write information
				fflush(log);

				//set the write lock
				writeLock = true;
			}

			return;
		}
	}
	else
	{
		//other string wants to write in log
		//so reset counter
		timesLastStringWritten = 0;

		//and deactivate write lock
		writeLock = false;
	}

	//either way update lastString
	lastString.clear();
	lastString = text;

	//start a html paragraph
	fprintf_s(log, "<p");

	//check if message is critical
	if (critical)
	{
		//if it is make it visible in log
		fprintf_s(log, " style=\"background-color:#800000; ");
	}
	else
	{
		//else just stay normal
		fprintf_s(log, " style=\"");
	}

	//look which color to choose
	switch (color)
	{
		//and color the text accordingly
		case log_color::BLACK:
		{
			fprintf_s(log, "color:#000000;\">%s", text);
		}break;
		case log_color::WHITE:
		{
			fprintf_s(log, "color:#FFFFFF;\">%s", text);
		}break;
		case log_color::RED:
		{
			fprintf_s(log, "color:#FF0000;\">%s", text);
		}break;
		case log_color::GREEN:
		{
			fprintf_s(log, "color:#00FF00;\">%s", text);
		}break;
		case log_color::BLUE:
		{
			fprintf_s(log, "color:#0000FF;\">%s", text);
		}break;
		case log_color::YELLOW:
		{
			fprintf_s(log, "color:#FFFF00;\">%s", text);
		}break;
		case log_color::PURPLE:
		{
			fprintf_s(log, "color:#FF00FF;\">%s", text);
		}break;
		case log_color::CYAN:
		{
			fprintf_s(log, "color:#00FFFF;\">%s", text);
		}break;
		case log_color::DEFAULT:
		{
			fprintf_s(log, "\">%s", text);
		}break;
		default:
		{
			fprintf_s(log, "\">%s", text);
		}break;
	}

	//end the html paragraph and add a line break
	fprintf_s(log, "</p><br/>");

	//force logfile to write information
	fflush(log);
}

void logfile::writeToLog(const char* text, const char* color)
{
	writeToLog(text, color, false);
}

void logfile::writeToLog(const char* text, const char* color, bool critical)
{
	//check whether new text equals last text
	if (lastString._Equal(text))
	{
		//it is so higher the number this string got written to the log
		timesLastStringWritten++;

		//check whether the string got written to the log to many times
		if (timesLastStringWritten > 2)
		{
			//check if this message was already written
			if (!writeLock)
			{
				//if not write message to log that a string was limited to a certain amount of times
				fprintf_s(log, "<p style=\"color:#FF0000;\">The following string has been limited due to too frequently usage: %s</p><br/>", text);

				//force logfile to write information
				fflush(log);

				//set the write lock
				writeLock = true;
			}

			return;
		}
	}
	else
	{
		//other string wants to write in log
		//so reset counter
		timesLastStringWritten = 0;

		//and deactivate write lock
		writeLock = false;
	}

	//either way update lastString
	lastString.clear();
	lastString = text;

	//add a html paragraph
	fprintf_s(log, "<p");

	//check if message is critical
	if (critical)
	{
		//if it is make it visible
		fprintf_s(log, " style=\"background-color:#800000; ");
	}
	else
	{
		//else just stay normal
		fprintf_s(log, " style=\"");
	}

	//color the text with the given color
	fprintf_s(log, "color:#%s;\">%s", color, text);

	//end the html paragraph and add a line break
	fprintf_s(log, "</p><br/>");

	//force logfile to write information
	fflush(log);
}

void logfile::writeToLogf(const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log
	writeToLog(final_text);
}

void logfile::writeToLogf(log_color color, const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log and add the color
	writeToLog(final_text, color);
}

void logfile::writeToLogf(log_color color, bool critical, const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log and add color and critical info
	writeToLog(final_text, color, critical);
}

void logfile::writeToLogf(const char* color, const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log and add color
	writeToLog(final_text, color);
}

void logfile::writeToLogf(const char* color, bool critical, const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log and add color and critical info
	writeToLog(final_text, color, critical);
}
