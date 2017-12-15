/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Released under the terms of the MIT license.
 *
 * Authors:
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */


#include "ChoiceView.h"

#include <LayoutBuilder.h>

#include <stdio.h>


#define MSG_ANSWER_CHANGED 'chg'


ChoiceView::ChoiceView()
	:
	BView(NULL, B_SUPPORTS_LAYOUT | B_FULL_UPDATE_ON_RESIZE),
	fChoiceCount(0)
{
	SetViewColor(tint_color(ui_color(B_PANEL_BACKGROUND_COLOR),
		B_LIGHTEN_2_TINT));

	fQuestionView = new BStringView("question text", "");

	for (int i = 0; i < MAX_CHOICES; i++) {
		char name[8];
		snprintf(name, 8, "item %d", i);
		fChoices[i] = new BRadioButton(name, NULL, new BMessage(MSG_ANSWER_CHANGED));
	}

	BLayoutBuilder::Group<>(this, B_VERTICAL)
		.SetInsets(5, 5, 5, 5)
		.AddGrid()
			.Add(fQuestionView, 0, 0)
			.Add(fChoices[0], 0, 1)
			.Add(fChoices[1], 0, 2)
			.Add(fChoices[2], 0, 3)
			.Add(fChoices[3], 0, 4)
			.Add(fChoices[4], 0, 5)
			.Add(fChoices[5], 0, 6)
			.Add(fChoices[6], 0, 7)
			.Add(fChoices[7], 0, 8)
			.End()
		.AddGlue();

	Empty();
}


ChoiceView::~ChoiceView()
{
}


void
ChoiceView::AddChoice(const char* name, BString choice)
{
	if (fChoiceCount <= MAX_CHOICES && fChoices[fChoiceCount] != NULL) {
		fChoices[fChoiceCount]->SetLabel(choice);
		fChoices[fChoiceCount]->Show();
		fChoiceCount++;
	} else {
		printf("Error: too many choices: %d\n", fChoiceCount);
	}
}


void
ChoiceView::SetQuestion(BString question)
{
	fQuestionView->SetText(question);
}


void
ChoiceView::Empty() {
	fQuestionView->SetText("");
	for (int i = 0; i < MAX_CHOICES; i++)
		fChoices[i]->Hide();
}
