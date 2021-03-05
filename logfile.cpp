#include "logfile.hpp"

c_logfile::c_logfile()
{
	//define the file
	fopen_s(&mv_logfile, mv_logName, "w");

	//check file stream
	if (mv_logfile == NULL)
	{
		MessageBox(NULL, "Logfile initialisation failed", "Error", MB_OK | MB_ICONERROR);
		return;
	}
	
	//make html header
	fprintf_s(mv_logfile, "<html><head><title>LOG</title></head><body style=\"background-color:#2a2a2a; font-family:Consolas; color:lightgray\">");
	fprintf_s(mv_logfile, "<h1 style=\"font-size:42px;\">Logfile</h1>");
#ifdef _DEBUG
	fprintf_s(mv_logfile, "<h1 style=\"font-size:40px;\">Build: Debug</h1>");
#else
	fprintf_s(mv_logfile, "<h1 style=\"font-size:40px;\">Build: Release</h1>");
#endif
	fprintf_s(mv_logfile, "<hr/>");

	//close and open log in append mode
	fclose(mv_logfile);
	fopen_s(&mv_logfile, mv_logName, "a");
}

c_logfile::~c_logfile()
{
	//write html bottom
	fprintf_s(mv_logfile, "</body></html>");

	//close log after program shutdown
	fclose(mv_logfile);
}

void c_logfile::mf_writeToLog(const char* text)
{
	mf_writeToLog(text, COLOR::DEFAULT);
}

void c_logfile::mf_writeToLog(const char* text, e_color color)
{
	mf_writeToLog(text, color, false);
}

void c_logfile::mf_writeToLog(const char* text, e_color color, bool critical)
{
	//check wether new text equals last text
	if (mv_lastString._Equal(text))
	{
		//it is so higher the number this string got written to the log
		mv_timesLastStringWritten++;

		//check wether the string got written to the log to many times
		if (mv_timesLastStringWritten > 2)
		{
			//check if this message was already written
			if (!mv_writeLock)
			{
				//if not write message to log that a string was limited to a certain amount of times
				fprintf_s(mv_logfile, "<p style=\"color:#FF0000;\">The following string has been limited due to too frequently usage: %s</p><br/>", text);

				//force logfile to write information
				fflush(mv_logfile);

				//set the write lock
				mv_writeLock = true;
			}

			return;
		}
	}
	else
	{
		//other string wants to write in log
		//so reset counter
		mv_timesLastStringWritten = 0;

		//and deactivate write lock
		mv_writeLock = false;
	}

	//either way update lastString
	mv_lastString.clear();
	mv_lastString = text;

	//start a html paragraph
	fprintf_s(mv_logfile, "<p");

	//check if message is critical
	if (critical)
	{
		//if it is make it visible in log
		fprintf_s(mv_logfile, " style=\"background-color:#800000; ");
	}
	else
	{
		//else just stay normal
		fprintf_s(mv_logfile, " style=\"");
	}

	//look which color to choose
	switch (color)
	{
		//and color the text accordingly
		case COLOR::BLACK:
		{
			fprintf_s(mv_logfile, "color:#000000;\">%s", text);
		}break;
		case COLOR::WHITE:
		{
			fprintf_s(mv_logfile, "color:#FFFFFF;\">%s", text);
		}break;
		case COLOR::RED:
		{
			fprintf_s(mv_logfile, "color:#FF0000;\">%s", text);
		}break;
		case COLOR::GREEN:
		{
			fprintf_s(mv_logfile, "color:#00FF00;\">%s", text);
		}break;
		case COLOR::BLUE:
		{
			fprintf_s(mv_logfile, "color:#0000FF;\">%s", text);
		}break;
		case COLOR::YELLOW:
		{
			fprintf_s(mv_logfile, "color:#FFFF00;\">%s", text);
		}break;
		case COLOR::PURPLE:
		{
			fprintf_s(mv_logfile, "color:#FF00FF;\">%s", text);
		}break;
		case COLOR::CYAN:
		{
			fprintf_s(mv_logfile, "color:#00FFFF;\">%s", text);
		}break;
		case COLOR::DEFAULT:
		{
			fprintf_s(mv_logfile, "\">%s", text);
		}break;
		default:
		{
			fprintf_s(mv_logfile, "\">%s", text);
		}break;
	}

	//end the html paragraph and add a line break
	fprintf_s(mv_logfile, "</p><br/>");

	//force logfile to write information
	fflush(mv_logfile);
}

void c_logfile::mf_writeToLog(const char* text, const char* color)
{
	mf_writeToLog(text, color, false);
}

void c_logfile::mf_writeToLog(const char* text, const char* color, bool critical)
{
	//check wether new text equals last text
	if (mv_lastString._Equal(text))
	{
		//it is so higher the number this string got written to the log
		mv_timesLastStringWritten++;

		//check wether the string got written to the log to many times
		if (mv_timesLastStringWritten > 2)
		{
			//check if this message was already written
			if (!mv_writeLock)
			{
				//if not write message to log that a string was limited to a certain amount of times
				fprintf_s(mv_logfile, "<p style=\"color:#FF0000;\">The following string has been limited due to too frequently usage: %s</p><br/>", text);

				//force logfile to write information
				fflush(mv_logfile);

				//set the write lock
				mv_writeLock = true;
			}

			return;
		}
	}
	else
	{
		//other string wants to write in log
		//so reset counter
		mv_timesLastStringWritten = 0;

		//and deactivate write lock
		mv_writeLock = false;
	}

	//either way update lastString
	mv_lastString.clear();
	mv_lastString = text;

	//add a html paragraph
	fprintf_s(mv_logfile, "<p");

	//check if message is critical
	if (critical)
	{
		//if it is make it visible
		fprintf_s(mv_logfile, " style=\"background-color:#800000; ");
	}
	else
	{
		//else just stay normal
		fprintf_s(mv_logfile, " style=\"");
	}

	//color the text with the given color
	fprintf_s(mv_logfile, "color:#%s;\">%s", color, text);

	//end the html paragraph and add a line break
	fprintf_s(mv_logfile, "</p><br/>");

	//force logfile to write information
	fflush(mv_logfile);
}

void c_logfile::mf_writeToLogf(const char* text, ...)
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
	mf_writeToLog(final_text);
}

void c_logfile::mf_writeToLogf(e_color color, const char* text, ...)
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
	mf_writeToLog(final_text, color);
}

void c_logfile::mf_writeToLogf(e_color color, bool critical, const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log and add color and crit info
	mf_writeToLog(final_text, color, critical);
}

void c_logfile::mf_writeToLogf(const char* color, const char* text, ...)
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
	mf_writeToLog(final_text, color);
}

void c_logfile::mf_writeToLogf(const char* color, bool critical, const char* text, ...)
{
	//text to write in log
	TCHAR final_text[MAX_BUFFER];
	//list of arguments passed in ...
	va_list p_argList;

	//put string from arguments together
	va_start(p_argList, text);
	vsprintf_s(final_text, text, p_argList);
	va_end(p_argList);

	//write finished string in log and add color and crit info
	mf_writeToLog(final_text, color, critical);
}
