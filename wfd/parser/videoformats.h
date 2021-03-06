/*
 * This file is part of wysiwidi
 *
 * Copyright (C) 2014 Intel Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */


#ifndef VIDEOFORMATS_H_
#define VIDEOFORMATS_H_

#include "property.h"
#include "wfd/public/video_format.h"

#include <vector>

namespace wfd {

struct H264Codec {
 public:
  H264Codec(unsigned char profile, unsigned char level,
      unsigned int cea_support, unsigned int vesa_support,
      unsigned int hh_support, unsigned char latency,
      unsigned short min_slice_size, unsigned short slice_enc_params,
      unsigned char frame_rate_control_support,
      unsigned short max_hres, unsigned short max_vres);

  H264Codec(SelectableH264VideoFormat format);

  H264Codec(SupportedH264VideoFormats format);

  void ToSelectableVideoFormats(std::vector<SelectableH264VideoFormat>& formats) const;

  std::string ToString() const;

 private:
  unsigned char profile_;
  unsigned char level_;
  unsigned int cea_support_;
  unsigned int vesa_support_;
  unsigned int hh_support_;
  unsigned char latency_;
  unsigned short min_slice_size_;
  unsigned short slice_enc_params_;
  unsigned char frame_rate_control_support_;
  unsigned short max_hres_;
  unsigned short max_vres_;
};

typedef std::vector<wfd::H264Codec> H264Codecs;

class VideoFormats: public Property {
 public:
  VideoFormats();
  VideoFormats(NativeVideoFormat format,
               bool preferred_display_mode,
               const std::vector<SelectableH264VideoFormat>& h264_formats);
  VideoFormats(NativeVideoFormat format,
               bool preferred_display_mode,
               const std::vector<SupportedH264VideoFormats>& h264_formats);
  VideoFormats(unsigned char native,
               unsigned char preferred_display_mode,
               const H264Codecs& h264_codecs);
  ~VideoFormats() override;

  NativeVideoFormat GetNativeFormat() const;
  std::vector<SelectableH264VideoFormat> GetSelectableH264Formats() const;

  std::string ToString() const override;

 private:
  unsigned char native_;
  unsigned char preferred_display_mode_;
  H264Codecs h264_codecs_;
};

}  // namespace wfd

#endif  // VIDEOFORMATS_H_
