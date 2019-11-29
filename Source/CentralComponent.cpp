#include <cmath>
#include "CentralComponent.h"
<<<<<<< HEAD
=======
#include <cassert>
>>>>>>> 2de1697d880555346bf3f0252ed4736d1a0a6e8e

CentralComponent::CentralComponent()
	: Component("Central Component")
{
}

CentralComponent::~CentralComponent() {
<<<<<<< HEAD
}

void CentralComponent::paint(Graphics& g) {
	g.fillAll(Colour::fromRGB(100, 100, 200));
=======
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
>>>>>>> 2de1697d880555346bf3f0252ed4736d1a0a6e8e
}

void CentralComponent::resized() {

}