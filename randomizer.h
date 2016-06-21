#pragma once

#include <string>
#include <vector>

namespace DuelTopicRandomizer
{

struct Config
{
	size_t numberOfGroups_ = 0;
	size_t numberOfDuels_ = 0;
	size_t firstDuelNumber_ = 1;

	std::string inputFile_ = "";
	std::string outputFile_ = "";
};

class Randomizer
{
public:
	typedef std::vector<std::vector<std::string>> ResultType;
	Randomizer(const Config& config);
	ResultType getTopics();
	void saveUnusedTopics();

private:
	std::vector<std::string> topics_;
	Config config_;
};

}
