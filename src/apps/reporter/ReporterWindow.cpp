/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Released under the terms of the MIT license.
 *
 * Authors:
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */


#include "ReporterWindow.h"

#include <Button.h>
#include <Catalog.h>
#include <LayoutBuilder.h>


#define B_TRANSLATION_CONTEXT "Reporter Window"

#define MSG_ACTION_NEXT 'next'
#define MSG_ACTION_EXIT 'exit'


ReporterWindow::ReporterWindow(BRect frame)
	: BWindow(frame, B_TRANSLATE("Problem Reporter"), B_TITLED_WINDOW_LOOK,
		B_NORMAL_WINDOW_FEEL, B_NOT_ZOOMABLE /*| B_NOT_RESIZABLE*/,
		B_CURRENT_WORKSPACE)
{
	//IntroductionStep();
	DiagnoseStep();
}


ReporterWindow::~ReporterWindow()
{
}


void
ReporterWindow::IntroductionStep()
{
	BButton* nextButton = new BButton("next", B_TRANSLATE("Continue"),
		new BMessage(MSG_ACTION_NEXT));
	nextButton->MakeDefault(true);

	BButton* exitButton = new BButton("exit", B_TRANSLATE("Exit"),
		new BMessage(MSG_ACTION_EXIT));
	fIntroView = new IntroView();
	BLayoutBuilder::Group<>(this, B_VERTICAL)
		.SetInsets(5, 5, 5, 5)
		.AddGrid()
			.Add(fIntroView, 0, 0, 3)
			.Add(exitButton, 1, 1)
			.Add(nextButton, 2, 1)
			.End();
}


void
ReporterWindow::DiagnoseStep() {
	fChoiceView = new ChoiceView();

	BButton* nextButton = new BButton("next", B_TRANSLATE("Continue"),
		new BMessage(MSG_ACTION_NEXT));
	nextButton->MakeDefault(true);
	nextButton->SetEnabled(false);

	BButton* exitButton = new BButton("exit", B_TRANSLATE("Exit"),
		new BMessage(MSG_ACTION_EXIT));

	BLayoutBuilder::Group<>(this, B_VERTICAL)
		.SetInsets(5, 5, 5, 5)
		.AddGrid()
			.Add(fChoiceView, 0, 0, 3)
			.Add(exitButton, 1, 1)
			.Add(nextButton, 2, 1)
			.End();

	fChoiceView->SetQuestion(
		B_TRANSLATE("Which kind of issue are you having?"));

	fChoiceView->AddChoice("unstable", B_TRANSLATE("Instability"));
	fChoiceView->AddChoice("video", B_TRANSLATE("Video Card Problems"));
	fChoiceView->AddChoice("net", B_TRANSLATE("Network Card Problems"));
	fChoiceView->AddChoice("storage", B_TRANSLATE("Storage Device"));
	fChoiceView->AddChoice("package", B_TRANSLATE("Software Packaging"));
}
