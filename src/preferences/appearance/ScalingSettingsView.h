/*
 * Copyright 2017, Haiku, Inc. All rights reserved.
 * Released under the terms of the MIT license.
 */
#ifndef SCALING_SETTINGS_VIEW_H
#define SCALING_SETTINGS_VIEW_H


#include <View.h>
#include <Slider.h>
#include <TextView.h>


class ScalingSettingsView : public BView {
public:
							ScalingSettingsView(const char* name);
	virtual					~ScalingSettingsView();

	virtual	void			AttachedToWindow();
	virtual	void			MessageReceived(BMessage* message);

			void			SetDefaults();
			void			Revert();
			bool			IsDefaultable();
			bool			IsRevertable();

protected:
			void			_UpdateSettings();
			float			_ScaleToFloat(int scale);
			int				_ScaleToInt(float scale);

private:
			BSlider*		fScaleControl;
			BTextView*		fScaleLabel;
};

#endif /* SCALING_SETTINGS_VIEW */
