#include "cli.h"

#include <cstring>
#include <iostream>

namespace DuelTopicRandomizer
{

RandomizerCli::RandomizerCli(int argc, char** argv)
{
	try
	{
		parseArgs(argc, argv);
	}
	catch (std::exception& ex)
	{
		std::cerr << "Error during arguments parsing: " << ex.what() << std::endl;
		printUsage(argv[0]);
		throw ex;
	}
}

Config RandomizerCli::getConfig() const
{
	return config_;
}

void RandomizerCli::printResults(const Randomizer::ResultType& results) const
{
	char groupName = 'A';
	size_t duelNumber = config_.firstDuelNumber_;

	for (auto& group : results)
	{
		std::cout << "Grupa: " << groupName++ << "\n";
		for (auto& duel : group)
		{
			std::cout << "Pojedynek " << duelNumber++ << ".  - " << duel << "\n";
		}
		std::cout << "\n";
	}
}

void RandomizerCli::parseArgs(int argc, char** argv)
{
	// TODO: use some library
	int i = 1;
	while (i + 1 < argc)
	{
		std::string value(argv[i+1]);
		if (strcmp(argv[i], "--input") == 0)
		{
			config_.inputFile_ = value;
		}
		else if (strcmp(argv[i], "--output") == 0)
		{
			config_.outputFile_ = value;
		}
		else if (strcmp(argv[i], "-g") == 0)
		{
			config_.numberOfGroups_ = std::stoul(value);
		}
		else if (strcmp(argv[i], "-d") == 0)
		{
			config_.numberOfDuels_ = std::stoul(value);
		}
		else if (strcmp(argv[i], "-s") == 0)
		{
			config_.firstDuelNumber_ = std::stoul(value);
		}
		else
		{
			throw std::runtime_error(std::string("Unknown parameter: ") + argv[i]);
		}

		i += 2;
	}

	if (config_.inputFile_.empty() || config_.outputFile_.empty() || config_.numberOfGroups_ == 0 || config_.numberOfDuels_ == 0)
		throw std::runtime_error("Invalid arguments");
}

void RandomizerCli::printUsage(const char* name)
{
	std::cout << "Usage: " << name << "-g <number of groups> -d <number of duels> [-s <seq. number of first duel>]  --input <input file> --output <output file>" << std::endl;
}

}
