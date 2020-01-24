#include "Utility.h"
#include <string>
#include <vector>

namespace utilities
{
	std::vector<std::string> explode(std::string &src, char delimeter)
	{
		std::vector<std::string> outputList{};
		int backPos{0};
		int frontPos{0};
		while(true)
		{
			frontPos = src.find_first_of(delimeter, frontPos + 1);
			if(frontPos == std::string::npos)
				break;
			outputList.push_back(src.substr(backPos, frontPos - backPos));
			backPos = frontPos;
		}
		return outputList;
	}
}

