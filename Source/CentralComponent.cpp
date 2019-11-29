#include <cmath>
#include "CentralComponent.h"
#include <cassert>

CentralComponent::CentralComponent()
	: Component("Central Component")
{
}

CentralComponent::~CentralComponent() {
	th.join();
}

void CentralComponent::paint(Graphics& g) {
	assert(map.size() > 0);
	assert(map[0].size() > 0);
	auto wi = getWidth();
	auto hi = getHeight();
	auto wiStep = wi / map.size();
	auto hiStep = wi / map[0].size();
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			g.drawRect(i*wiStep, j*hiStep, wiStep, hiStep);
		}
	}
}

void CentralComponent::resized() {

}