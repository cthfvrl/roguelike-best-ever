#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <random>
#include <mutex>
#include <thread>
#include <condition_variable>

class CentralComponent
	: public Component
{
public:
	CentralComponent();
	~CentralComponent();

	void paint(Graphics&);
	void resized();

private:
<<<<<<< HEAD

=======
	std::thread th;
	std::vector<std::vector<Colour>> map;
>>>>>>> 2de1697d880555346bf3f0252ed4736d1a0a6e8e
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};
