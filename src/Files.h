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

using namespace std;

class File{
	string file_name;
	public:
		File(string n);
		int readFile();
		void saveFile();
};

#endif /* FILES_H_ */
