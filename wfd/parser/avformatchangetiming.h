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


#ifndef AVFORMATCHANGETIMING_H_
#define AVFORMATCHANGETIMING_H_

#include "property.h"

namespace wfd {

class AVFormatChangeTiming: public Property {
public:
  AVFormatChangeTiming(unsigned long long int pts, unsigned long long int dts);
  ~AVFormatChangeTiming() override;

  unsigned long long int pts() const { return pts_; }
  unsigned long long int dts() const { return dts_; }

  std::string ToString() const override;

 private:
  unsigned long long int pts_;
  unsigned long long int dts_;
};

}  // namespace wfd

#endif  // AVFORMATCHANGETIMING_H_
