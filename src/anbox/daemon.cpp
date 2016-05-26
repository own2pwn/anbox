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

#include <sys/prctl.h>
#include <signal.h>

#include "anbox/logger.h"
#include "anbox/daemon.h"
#include "anbox/config.h"

#include "anbox/cmds/version.h"
#include "anbox/cmds/run.h"
#include "anbox/cmds/shell.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace anbox {
Daemon::Daemon() :
    cmd{cli::Name{"anbox"}, cli::Usage{"anbox"}, cli::Description{"The Android in a Box runtime"}} {

    cmd.command(std::make_shared<cmds::Version>())
       .command(std::make_shared<cmds::Run>())
       .command(std::make_shared<cmds::Shell>());
}

int Daemon::Run(const std::vector<std::string> &arguments)
try {
    ensure_data_path();
    return cmd.run({std::cin, std::cout, arguments});
}
catch(std::exception &err) {
    ERROR("%s", err.what());
}

void Daemon::ensure_data_path() {
    if (!fs::is_directory(fs::path(config::data_path())))
        fs::create_directories(fs::path(config::data_path()));
}
} // namespace anbox
