#pragma once
#ifndef STRINGCOMMAND_H
#define STRINGCOMMAND_H

//#include <stdio.h>
#include <cstring>
#include "stdafx.h"
#include <iostream>

class char_array
{
	private:
		char* p_stringarray;					//initial input array
		char* p_inputstring;					//holds actual length data
		//char **pp_database_string;			//allocate data database.cpp
		int stringsize;							//holds array size to allocate memory
		int charinput;							//holds array input size
	
	public:
		inline char_array();					//inline so other functions can call on it
		inline ~char_array();
		inline void getinput(char*&);			//retrieves user input
		inline void grabline(char*&);			//retrieve line with whitespace included	NOT COMPLETE, may not need
		inline int sortline(char**&, char *&);	//sorts line into an array of strings and returns number of separate strings
		inline int arraysize();					//returns size of string array
		inline void printinput();				//print input string
		inline void changedefaultsize();		//change default input size	NOT COMPLETE
};

inline char_array::char_array()			//constructor
{
	stringsize = 0;
	charinput = 64;
	p_stringarray = new char[charinput];
}

inline char_array::~char_array()		//destructor
{
	delete[] p_inputstring, p_stringarray;
}

inline void char_array::getinput(char *&p_stringin)
{
	stringsize = 0;

	scanf("%63s", p_stringarray);	//get input string

	while (p_stringarray[stringsize] != NULL)	//finding out the size of string array
	{
		stringsize++;
	}
	stringsize++;

	p_inputstring = new char[stringsize];	//reallocate memory block and set array inside
	for (int i = 0; i < stringsize; i++)
	{
		p_inputstring[i] = p_stringarray[i];
	}
	
	p_inputstring[stringsize - 1] = NULL;

	p_stringin = new char[stringsize];		//set pp_stringin

	p_stringin = p_inputstring;
}

inline void char_array::grabline(char *&p_stringin)
{
	stringsize = 0;
	std::cin.getline(p_stringarray, charinput);
	while (p_stringarray[stringsize] != NULL)
	{
		stringsize++;
	}
	stringsize++;
	p_inputstring = new char[stringsize];
	
	for (int i = 0; i < stringsize; i++)
	{
		p_inputstring[i] = p_stringarray[i];
	}
	
	p_stringin = new char[stringsize];
	p_stringin = p_inputstring;
}

inline int char_array::sortline(char **&pp_stringin, char *&p_string);
{
	int position = 0;		//position in string
	int charcount = 1;			//how many characters there are
	int wordnum;			//which word is being processed
	int wordcount = 1;		//number of words in string
	int bookmark = 0;		//holds last known position

	while (p_string[position] == ' ')
	{
		position++;
	}

	wordnum = position;		//borrow wordnum to hold position value
	while (p_string[position] != NULL)	//find total inputted string word length
	{
		if (p_string[position] == ' ' && (p_string[position + 1] != ' ' || p_string[position + 1] != NULL))
		{
			wordcount++;
		}
		position++;
	}
	position = wordnum;		//set position to original value
	for (wordnum = 0; wordnum < wordcount; wordnum++)
	{
		charcount = 1;
		while (p_string[position] == ' ')
		{
			position++;
		}
		while (p_string[position] != ' ' && p_string[position] != NULL)
		{
			position++;
			charcount++;
		}
		pp_inputstring[wordnum] = new char[charcount];

		for (int i = 0; i < charcount; i++)
		{
			pp_inputstring[wordnum][i] = p_string[i + bookmark];
		}
		pp_inputstring[wordnum][charcount - 1] = NULL;
		bookmark = position + 1;
	}

	return wordcount;
}

inline int char_array::arraysize()
{
	if (stringsize != 0)
	{
		return stringsize;
	}
	else
	{
		printf("Array size is set at 0\n");
		return 0;
	}
}

inline void char_array::printinput()
{
	printf("%s", p_inputstring);
}

inline void char_array::changedefaultsize()
{
	printf("Input new default input string size: ");
	scanf("%i", charinput);
}

#endif