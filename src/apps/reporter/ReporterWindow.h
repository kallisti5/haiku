/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Released under the terms of the MIT license.
 *
 * Authors:
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */
#ifndef _REPORTER_WINDOW_H
#define _REPORTER_WINDOW_H


#include <Window.h>

#include "ChoiceView.h"
#include "IntroView.h"


class ReporterWindow : public BWindow {
public:
							ReporterWindow(BRect frame);
							~ReporterWindow();

	void					IntroductionStep();
	void					DiagnoseStep();

private:
	ChoiceView*				fChoiceView;
	IntroView*				fIntroView;
};


#endif /* _REPORTER_WINDOW_H */
