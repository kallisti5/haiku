/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Released under the terms of the MIT license.
 *
 * Authors:
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */
#ifndef _CHOICE_VIEW_H
#define _CHOICE_VIEW_H


#include <Window.h>
#include <String.h>
#include <StringView.h>
#include <RadioButton.h>

#define MAX_CHOICES 8


class ChoiceView : public BView {
public:
							ChoiceView();
							~ChoiceView();

		void				SetQuestion(BString question);
		void				AddChoice(const char* name, BString choice);
		void				Empty();

private:
		BStringView*		fQuestionView;
		BRadioButton*		fChoices[MAX_CHOICES];
		int					fChoiceCount;
};


#endif /* _CHOICE_VIEW_H */
