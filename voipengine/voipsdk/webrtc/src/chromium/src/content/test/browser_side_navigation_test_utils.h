// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_TEST_BROWSER_SIDE_NAVIGATION_TEST_UTILS_H_
#define CONTENT_TEST_BROWSER_SIDE_NAVIGATION_TEST_UTILS_H_

#include "base/macros.h"
#include "base/memory/scoped_ptr.h"

namespace content {

class StreamHandle;

// Initializes the browser side navigation test utils. Following this call, all
// NavigationURLLoader objects created will be TestNavigationURLLoaders instead
// of NavigationURLloaderImpls. This should be called before any call in the UI
// thread unit tests that will start a navigation (eg.
// TestWebContents::NavigateAndCommit).
void BrowserSideNavigationSetUp();

// Tears down the browser side navigation test utils.
void BrowserSideNavigationTearDown();

// Returns an empty stream. Used when faking a navigation commit notification
// from the IO thread with a TestNavigationURLLoader.
scoped_ptr<StreamHandle> MakeEmptyStream();

void EnableBrowserSideNavigation();

}  // namespace content

#endif  // CONTENT_TEST_BROWSER_SIDE_NAVIGATION_TEST_UTILS_H_
