#include "randomizer.h"

#include <algorithm>
#include <iterator>
#include <fstream>
#include <random>

namespace DuelTopicRandomizer
{

Randomizer::Randomizer(const std::string& topicsFile)
{
	std::fstream in(topicsFile, std::ios_base::in);
	while (in.good())
	{
		std::string topic;
		std::getline(in, topic);
		if (topic.size() > 0)
		{
			topics_.push_back(std::move(topic));
		}
	}
}

std::vector<std::vector<std::string>> Randomizer::getTopics(size_t groups, size_t duels)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<size_t> distr;
	
	std::vector<std::vector<std::string>> result;
	for (size_t g = 0; g < groups; ++g)
	{
		std::vector<std::string> group;
		for (size_t d = 0; d < duels; ++d)
		{
			size_t randomIndex = distr(rng, decltype(distr)::param_type(0, std::distance(begin(topics_), end(topics_))));
			auto iterator = std::next(begin(topics_), randomIndex);
			group.push_back(*iterator);
			topics_.erase(iterator);
		}
		result.push_back(std::move(group));
	}

	return result;
}

void Randomizer::saveUnusedTopics(const std::string& file)
{
	
	std::fstream out(file, std::ios_base::out);
	std::copy(begin(topics_), end(topics_),
			std::ostream_iterator<std::string>(out, "\n"));
	out.close();
}

}
