/*
 * Copyright 2017, Haiku, Inc.  All rights reserved.
 * Distributed under the terms of the MIT License.
 */


#include <View.h>

#include <stdio.h>

#include "ReporterApp.h"


#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "Reporter App"

const char *kReporterAppSig = "application/x-vnd.Haiku-Reporter";


ReporterApp::ReporterApp()
	:
	BApplication(kReporterAppSig)
{
}


ReporterApp::~ReporterApp()
{
}


void
ReporterApp::ReadyToRun()
{
	fReporterWindow = new ReporterWindow(BRect(150, 150, 550, 520));
	fReporterWindow->Show();
}


void
ReporterApp::MessageReceived(BMessage* message)
{
}
