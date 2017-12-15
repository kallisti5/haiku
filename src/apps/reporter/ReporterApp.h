/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef _REPORTER_APP_H_
#define _REPORTER_APP_H_


#include <Application.h>

#include "ReporterWindow.h"


class ReporterApp : public BApplication {
public:
					ReporterApp();
	virtual			~ReporterApp();

	void			ReadyToRun();
	void			MessageReceived(BMessage* message);

private:
	ReporterWindow* fReporterWindow;
};


#endif	// _REPORTER_APP_H_
