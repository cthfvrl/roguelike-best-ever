#include "MainForm.h"
#include "CentralComponent.h"

MainForm::MainForm() 
    : DocumentWindow(
	    JUCEApplication::getInstance()->getApplicationName(),
	    LookAndFeel_V4::getMidnightColourScheme().getUIColour(LookAndFeel_V4::ColourScheme::UIColour::windowBackground),
	    allButtons)
{
	setUsingNativeTitleBar(true);
	centreWithSize(static_cast<int>(getParentWidth()*0.9), static_cast<int>(getParentHeight()*0.9));
	setResizable(true, false);
	setVisible(true);
	centralComponent.reset(new CentralComponent());
	setContentOwned(centralComponent.get(), false);
}

MainForm::~MainForm() {
}

void MainForm::closeButtonPressed() {
	JUCEApplication::getInstance()->systemRequestedQuit();
}
