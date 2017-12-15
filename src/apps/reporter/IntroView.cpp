/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Released under the terms of the MIT license.
 *
 * Authors:
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */


#include "IntroView.h"

#include <Catalog.h>
#include <IconUtils.h>
#include <LayoutBuilder.h>

#include <stdio.h>


#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "Intro View"


IntroView::IntroView()
	:
	BView(NULL, B_SUPPORTS_LAYOUT | B_FULL_UPDATE_ON_RESIZE)
{
	SetViewColor(tint_color(ui_color(B_PANEL_BACKGROUND_COLOR),
		B_LIGHTEN_1_TINT));

	BBitmap introImage(BRect(0, 0, 64, 64), B_RGB32);
	BIconUtils::GetVectorIcon(kIntroIcon, sizeof(kIntroIcon), &introImage);

	BStringView* introTitle = new BStringView("title string",
		B_TRANSLATE("We're sorry you are having trouble with Haiku on this device."));
	BStringView* introInfo = new BStringView("title info",
		B_TRANSLATE("This tool will assist us to better understand your issue."));

	BLayoutBuilder::Group<>(this, B_VERTICAL)
		.SetInsets(5, 5, 5, 5)
		.AddGrid()
			.SetSpacing(0, 0)
			.Add(introTitle, 0, 1)
			.Add(introInfo, 0, 2)
			.End()
		.AddGlue();
}


IntroView::~IntroView()
{
}
