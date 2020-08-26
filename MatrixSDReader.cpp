#include "MatrixSDReader.h"


bool MatrixSDReader::InitSDReader(byte	CS_PIN)
{

	if (!SD.begin(CS_PIN))
	{
		return false;
	}

	return true;
}

bool MatrixSDReader::ReadNextAnimation(unsigned long* matrix, char numOfPix)
{
	
	if (m_AnimFile && m_AnimFile.available())
	{
		for (char i = 0; i < numOfPix; i++)
		{
			
			matrix[i] = strtol((m_AnimFile.readStringUntil(',').c_str()), NULL, 16);
			 //(m_AnimFile.readStringUntil(',').toInt());
		}

		return true;
	}
	else
	{
		if (!m_AnimFile)
		{
			m_CureentAnimationFile = -1;
		}


		m_AnimFile.close();

		m_CureentAnimationFile++;
		m_AnimFile = OpenNextFile();
	}
	return false;
	
}

File MatrixSDReader::OpenNextFile()
{
	return SD.open(String(m_CureentAnimationFile), FILE_READ);
	
}
