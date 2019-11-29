#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <random>
#include <mutex>
#include <thread>
#include <atomic>
#include <condition_variable>
#include "Map.h"

class CentralComponent
	: public Component
{
public:
	CentralComponent();
	~CentralComponent();

	void paint(Graphics&);
	void resized();

private:
	std::atomic<bool> shouldExit;
	std::thread loop;
	Map globalMap;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CentralComponent)
};
