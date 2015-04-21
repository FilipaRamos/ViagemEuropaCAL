/*
 * Files.h
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */

#ifndef FILES_H_
#define FILES_H_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File{
	string file_name;
	public:
		void readFile();
		void saveFile();
};

#endif /* FILES_H_ */
