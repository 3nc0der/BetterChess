#pragma once

#include <Windows.h>
#include <fstream>
#include "singleton.hpp"

using namespace std;

//max char buffer
//needed for formatted text
constexpr auto MAX_BUFFER = 1024;

//predefined colors
typedef enum class log_color
{
	BLACK = 0,
	WHITE = 1,
	BLUE = 2,
	GREEN = 3,
	RED = 4,
	PURPLE = 5,
	YELLOW = 6,
	CYAN = 7,
	DEFAULT = 8
}LOG_COLOR;

#define LOG c_logfile::get()

//logfile class, get an instance with the LOGFILE macro
class c_logfile : public singleton<c_logfile>
{
public:

	logfile();
	~logfile();

	//basic writetolog function
	void writeToLog(const char* text);

	//use one of the predefined colors
	void writeToLog(const char* text, log_color color);

	//if the message is critical it will be visible in the log
	void writeToLog(const char* text, log_color color, bool critical);

	//give the wanted color like this "RGB" aka "FF00FF"
	void writeToLog(const char* text, const char* color);

	//if the message is critical it will be visible in the log
	void writeToLog(const char* text, const char* color, bool critical);

	//basic writetolog formatted function
	void writeToLogf(const char* text, ...);

	//use one of the predefined colors
	void writeToLogf(log_color color, const char* text, ...);

	//if the message is critical it will be visible in the log
	void writeToLogf(log_color color, bool critical, const char* text, ...);

	//give the color like this "RGB" aka "FF00FF"
	void writeToLogf(const char* color, const char* text, ...);

	//if the message is critical it will be visible in the log
	void writeToLogf(const char* color, bool critical, const char* text, ...);

private:

	//file variable
	FILE *log;

	//holds current logfile name
	const char* logName = "logfile.html";

	//holds the last string that was written to log
	string lastString = "";

	//holds amount of last string written
	int timesLastStringWritten = 0;

	//tells wether the write lock is active or not
	bool writeLock = false;
};