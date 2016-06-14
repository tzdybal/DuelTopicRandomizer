#pragma once

#include <string>
#include <vector>

namespace DuelTopicRandomizer
{

class Randomizer
{
public:
	Randomizer(const std::string& topicsFile);
	std::vector<std::vector<std::string>> getTopics(size_t groups, size_t subgroups);
	void saveUnusedTopics(const std::string& file);
private:
	std::vector<std::string> topics_;
};

}
