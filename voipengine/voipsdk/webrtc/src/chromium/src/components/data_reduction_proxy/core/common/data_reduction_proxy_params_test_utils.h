// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_DATA_REDUCTION_PROXY_CORE_BROWSER_DATA_REDUCTION_PROXY_PARAMS_TEST_UTILS_H_
#define COMPONENTS_DATA_REDUCTION_PROXY_CORE_BROWSER_DATA_REDUCTION_PROXY_PARAMS_TEST_UTILS_H_

#include "components/data_reduction_proxy/core/common/data_reduction_proxy_params.h"

namespace data_reduction_proxy {

class TestDataReductionProxyParams : public DataReductionProxyParams {
 public:
  // Used to emulate having constants defined by the preprocessor.
  enum HasNames {
    HAS_NOTHING = 0x0,
    HAS_DEV_ORIGIN = 0x1,
    HAS_ORIGIN = 0x2,
    HAS_FALLBACK_ORIGIN = 0x4,
    HAS_SSL_ORIGIN = 0x08,
    HAS_ALT_ORIGIN = 0x10,
    HAS_ALT_FALLBACK_ORIGIN = 0x20,
    HAS_PROBE_URL = 0x40,
    HAS_DEV_FALLBACK_ORIGIN = 0x80,
    HAS_EVERYTHING = 0xff,
  };

  TestDataReductionProxyParams(int flags,
                               unsigned int has_definitions);
  bool init_result() const;

  // Test values to replace the values specified in preprocessor defines.
  static std::string DefaultDevOrigin();
  static std::string DefaultDevFallbackOrigin();
  static std::string DefaultOrigin();
  static std::string DefaultFallbackOrigin();
  static std::string DefaultSSLOrigin();
  static std::string DefaultAltOrigin();
  static std::string DefaultAltFallbackOrigin();
  static std::string DefaultProbeURL();

  static std::string FlagOrigin();
  static std::string FlagFallbackOrigin();
  static std::string FlagSSLOrigin();
  static std::string FlagAltOrigin();
  static std::string FlagAltFallbackOrigin();
  static std::string FlagProbeURL();

 protected:
  std::string GetDefaultDevOrigin() const override;

  std::string GetDefaultDevFallbackOrigin() const override;

  std::string GetDefaultOrigin() const override;

  std::string GetDefaultFallbackOrigin() const override;

  std::string GetDefaultSSLOrigin() const override;

  std::string GetDefaultAltOrigin() const override;

  std::string GetDefaultAltFallbackOrigin() const override;

  std::string GetDefaultProbeURL() const override;

 private:
  std::string GetDefinition(unsigned int has_def,
                            const std::string& definition) const;

  unsigned int has_definitions_;
  bool init_result_;

};
}  // namespace data_reduction_proxy
#endif  // COMPONENTS_DATA_REDUCTION_PROXY_CORE_BROWSER_DATA_REDUCTION_PROXY_PARAMS_TEST_UTILS_H_

