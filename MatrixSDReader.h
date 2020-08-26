#ifndef MATRIX_SD_READER_H

#define MATRIX_SD_READER_H
#include <SPI.h>
#include <SD.h>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */


class MatrixSDReader
{
public:
	 bool ReadNextAnimation(unsigned long* matrix, char numOfPix);
	 bool InitSDReader(byte CS_PIN);
protected:
	File OpenNextFile();
private:
	int m_CureentAnimationFile =  -1;
	File m_AnimFile;
};

#endif