/*
 * Copyright 2017, Haiku, Inc. All rights Reserved.
 * Distributed under the terms of the MIT License.
 */


#include "ScalingSettingsView.h"

#include <stdio.h>
#include <stdlib.h>

#include <Box.h>
#include <Catalog.h>
#include <LayoutBuilder.h>
#include <Locale.h>
#include <MenuField.h>
#include <MenuItem.h>
#include <PopUpMenu.h>
#include <Slider.h>
#include <SpaceLayoutItem.h>
#include <String.h>
#include <TextView.h>

#include "APRWindow.h"


#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "ScalingSettingsView"

#define B_SCALE_MIN 0.75
#define B_SCALE_MAX 4.0
#define B_SCALE_INCREMENT 0.125


static const int32 kMsgSetScale = 'scal';


ScalingSettingsView::ScalingSettingsView(const char* name)
	: BView(name, 0)
{
	fScaleControl = new BSlider("overallScaleControl",
		B_TRANSLATE("User interface scale:"),
		new BMessage(kMsgSetScale), 0, 255, B_HORIZONTAL);
	fScaleControl->SetHashMarks(B_HASH_MARKS_BOTTOM);
	fScaleControl->SetHashMarkCount(B_SCALE_MAX);
	fScaleControl->SetLimits((B_SCALE_MIN / B_SCALE_INCREMENT), _ScaleToInt(B_SCALE_MAX));
	char minIncrementLabel[8];
	char maxIncrementLabel[8];
	snprintf(minIncrementLabel, 8, "%01.01fx", B_SCALE_MIN);
	snprintf(maxIncrementLabel, 8, "%01.01fx", B_SCALE_MAX);
	fScaleControl->SetLimitLabels(minIncrementLabel, maxIncrementLabel);

	fScaleControl->SetValue(_ScaleToInt(1.0));

	fScaleLabel = new BTextView("overallScaleValue");
	fScaleLabel->SetText("0.0x");
	fScaleLabel->SetViewUIColor(B_PANEL_BACKGROUND_COLOR);
	fScaleLabel->MakeEditable(false);
	fScaleLabel->MakeSelectable(false);

	BLayoutBuilder::Grid<>(this, B_USE_DEFAULT_SPACING, B_USE_DEFAULT_SPACING)
		.Add(fScaleControl, 0, 2, 2)
		.Add(fScaleLabel, 0, 3, 2)
		.AddGlue(0, 4)
		.SetInsets(B_USE_WINDOW_SPACING);

	_UpdateSettings();
}


ScalingSettingsView::~ScalingSettingsView()
{
}


void
ScalingSettingsView::AttachedToWindow()
{
	AdoptParentColors();

	if (Parent() == NULL)
		SetViewUIColor(B_PANEL_BACKGROUND_COLOR);

	fScaleControl->SetTarget(this);
}


void
ScalingSettingsView::MessageReceived(BMessage *msg)
{
	switch (msg->what) {
		case kMsgSetScale:
			_UpdateSettings();
			Window()->PostMessage(kMsgUpdate);
			break;
		default:
			BView::MessageReceived(msg);
	}
}


void
ScalingSettingsView::SetDefaults()
{
	if (!IsDefaultable())
		return;
	fScaleControl->SetValue(_ScaleToInt(1.0));
}


bool
ScalingSettingsView::IsDefaultable()
{
	return true;
}


bool
ScalingSettingsView::IsRevertable()
{
	return false;
}


void
ScalingSettingsView::Revert()
{
	if (!IsRevertable())
		return;
}


float
ScalingSettingsView::_ScaleToFloat(int sliderScale)
{
    return sliderScale * B_SCALE_INCREMENT;
}


int
ScalingSettingsView::_ScaleToInt(float scale)
{
    return scale / B_SCALE_INCREMENT;
}


void
ScalingSettingsView::_UpdateSettings()
{
	char currentLevel[8];
	snprintf(currentLevel, 8, "%01.01fx", _ScaleToFloat(fScaleControl->Value()));
	fScaleLabel->SetText(currentLevel);
}
