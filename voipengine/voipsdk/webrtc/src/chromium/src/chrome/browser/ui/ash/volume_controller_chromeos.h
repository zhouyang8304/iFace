// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_ASH_VOLUME_CONTROLLER_CHROMEOS_H_
#define CHROME_BROWSER_UI_ASH_VOLUME_CONTROLLER_CHROMEOS_H_

#include "ash/volume_control_delegate.h"
#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "chromeos/audio/cras_audio_handler.h"

// A class which controls volume when F8-10 or a multimedia key for volume is
// pressed.
class VolumeController : public ash::VolumeControlDelegate,
                         public chromeos::CrasAudioHandler::AudioObserver {
 public:
  VolumeController();
  virtual ~VolumeController();

  // Overridden from ash::VolumeControlDelegate:
  virtual void HandleVolumeMute(const ui::Accelerator& accelerator) override;
  virtual void HandleVolumeDown(const ui::Accelerator& accelerator) override;
  virtual void HandleVolumeUp(const ui::Accelerator& accelerator) override;

  // Overridden from chromeos::CrasAudioHandler::AudioObserver.
  virtual void OnOutputVolumeChanged() override;
  virtual void OnOutputMuteChanged() override;

 private:

  DISALLOW_COPY_AND_ASSIGN(VolumeController);
};

#endif  // CHROME_BROWSER_UI_ASH_VOLUME_CONTROLLER_CHROMEOS_H_
