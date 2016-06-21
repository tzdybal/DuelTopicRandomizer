#pragma once

#include "randomizer.h"

namespace DuelTopicRandomizer
{

class RandomizerCli
{
public:
	RandomizerCli(int argc, char** argv);
	Config getConfig() const; 
	void printResults(const Randomizer::ResultType& results) const;
private:
	void parseArgs(int argc, char** argv);
	void printUsage(const char* name);
	Config config_;
};

}
