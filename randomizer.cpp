#include "randomizer.h"

#include <algorithm>
#include <iterator>
#include <fstream>
#include <random>

namespace DuelTopicRandomizer
{

Randomizer::Randomizer(const Config& config)
	: config_(config)
{
	std::fstream in(config_.inputFile_, std::ios_base::in);
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

Randomizer::ResultType Randomizer::getTopics()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<size_t> distr;
	
	ResultType result;
	for (size_t g = 0; g < config_.numberOfGroups_; ++g)
	{
		std::vector<std::string> group;
		for (size_t d = 0; d < config_.numberOfDuels_; ++d)
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

void Randomizer::saveUnusedTopics()
{
	
	std::fstream out(config_.outputFile_, std::ios_base::out);
	std::copy(begin(topics_), end(topics_),
			std::ostream_iterator<std::string>(out, "\n"));
	out.close();
}

}
