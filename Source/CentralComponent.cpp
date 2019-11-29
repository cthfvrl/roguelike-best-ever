#include <cmath>
#include "CentralComponent.h"
#include <cassert>
#include <thread>
#include <chrono>

CentralComponent::CentralComponent()
	: Component("Central Component")
	, shouldExit(false)
{
	auto globalLoop = [th = this, &shouldExit = shouldExit, & map = globalMap]() {
		using namespace std::chrono_literals;
		while (!shouldExit) {
			auto& mp = map.getMap();
			for (auto& e : mp)
				for (auto& v : e)
					v.move();
			th->repaint();
			std::this_thread::sleep_for(1s);
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
	int hiStep = hi / map[0].size();
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			g.setColour(map[i][j].getColour());
			g.fillRect(i*wiStep, j*hiStep, wiStep, hiStep);
		}
	}
}

void CentralComponent::resized() {

}