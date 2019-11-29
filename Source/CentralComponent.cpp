#include <cmath>
#include "CentralComponent.h"
#include <cassert>

CentralComponent::CentralComponent()
	: Component("Central Component")
	, shouldExit(false)
{
	auto globalLoop = [&shouldExit = shouldExit, &map = globalMap]() {
		while (!shouldExit) {

		}
	};

	loop = std::thread(globalLoop);
}

CentralComponent::~CentralComponent() {
	shouldExit = true;
	loop.join();
}

void CentralComponent::paint(Graphics& g) {
	const auto &map = globalMap.getMap();
	assert(map.size() > 0);
	assert(map[0].size() > 0);
	int wi = getWidth();
	int hi = getHeight();
	int wiStep = wi / map.size();
	int hiStep = wi / map[0].size();
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			g.setColour(map[i][j].getColour());
			g.drawRect(i*wiStep, j*hiStep, wiStep, hiStep);
		}
	}
}

void CentralComponent::resized() {

}