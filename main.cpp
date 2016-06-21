#include "randomizer.h"
#include "cli.h"

int main(int argc, char** argv)
{
	using namespace DuelTopicRandomizer;

	RandomizerCli cli(argc, argv);
	Config config = cli.getConfig();
	Randomizer randomizer(config);
	cli.printResults(randomizer.getTopics());
	randomizer.saveUnusedTopics();


}
