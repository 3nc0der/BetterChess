#pragma once

#include <Windows.h>
#include <fstream>
#include "singleton.hpp"

using namespace std;

//max char buffer
//needed for formatted text
constexpr auto MAX_BUFFER = 1024;

//predefined colors
typedef enum e_color
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
}COLOR;

//logfile class, get an instance with the LOGFILE macro
class c_logfile : public c_singleton<c_logfile>
{
public:

	c_logfile();
	~c_logfile();

	//basic writetolog function
	void mf_writeToLog(const char* text);

	//use one of the predefined colors
	void mf_writeToLog(const char* text, e_color color);

	//if the message is critical it will be visible in the log
	void mf_writeToLog(const char* text, e_color color, bool critical);

	//give the wanted color like this "RGB" aka "FF00FF"
	void mf_writeToLog(const char* text, const char* color);

	//if the message is critical it will be visible in the log
	void mf_writeToLog(const char* text, const char* color, bool critical);

	//basic writetolog formatted function
	void mf_writeToLogf(const char* text, ...);

	//use one of the predefined colors
	void mf_writeToLogf(e_color color, const char* text, ...);

	//if the message is critical it will be visible in the log
	void mf_writeToLogf(e_color color, bool critical, const char* text, ...);

	//give the color like this "RGB" aka "FF00FF"
	void mf_writeToLogf(const char* color, const char* text, ...);

	//if the message is critical it will be visible in the log
	void mf_writeToLogf(const char* color, bool critical, const char* text, ...);

private:

	//file variable
	FILE *mv_logfile;

	//holds current logfile name
	const char* mv_logName = "logfile.html";

	//holds the last string that was written to log
	string mv_lastString = "";

	//holds amount of last string written
	int mv_timesLastStringWritten = 0;

	//tells wether the write lock is active or not
	bool mv_writeLock = false;
};