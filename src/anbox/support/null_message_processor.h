/*
 * Copyright (C) 2016 Simon Fels <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ANBOX_SUPPORT_NULL_MESSAGE_PROCESSOR_H_
#define ANBOX_SUPPORT_NULL_MESSAGE_PROCESSOR_H_

#include <memory>

#include <boost/asio.hpp>

#include "anbox/runtime.h"
#include "anbox/network/message_processor.h"

namespace anbox {
namespace support {
class NullMessageProcessor : public network::MessageProcessor {
public:
    NullMessageProcessor();
    ~NullMessageProcessor();

    bool process_data(const std::vector<std::uint8_t> &data) override;
};
} // namespace graphics
} // namespace anbox

#endif
