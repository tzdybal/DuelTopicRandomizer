#include <iostream>

#include "randomizer.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " topics_file unused_topics_file" << std::endl;
		return EXIT_FAILURE;
	}
	DuelTopicRandomizer::Randomizer randomizer(argv[1]);
	auto groups = randomizer.getTopics(6, 3);
	char groupName = 'A';
	size_t duelNumber = 1;
	for (auto& group : groups)
	{
		std::cout << "Grupa: " << groupName++ << "\n";
		for (auto& duel : group)
		{
			std::cout << "Pojedynek " << duelNumber++ << ".  - " << duel << "\n";
		}
		std::cout << "\n";
	}
	randomizer.saveUnusedTopics(argv[2]);
}
