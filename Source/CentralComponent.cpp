#include <cmath>
#include "CentralComponent.h"

CentralComponent::CentralComponent()
	: Component("Central Component")
{
}

CentralComponent::~CentralComponent() {
}

void CentralComponent::paint(Graphics& g) {
	g.fillAll(Colour::fromRGB(100, 100, 200));
}

void CentralComponent::resized() {

}