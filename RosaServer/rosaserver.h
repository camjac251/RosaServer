﻿#pragma once

#include <fstream>
#include <iostream>
#include <thread>

#define SOL_SAFE_FUNCTION_CALLS 1
#include "sol/sol.hpp"
#include "subhook.h"

#include "api.h"
#include "childprocess.h"
#include "console.h"
#include "engine.h"
#include "filewatcher.h"
#include "hooks.h"
#include "image.h"
#include "opusencoder.h"
#include "server.h"
#include "sqlite.h"
#include "worker.h"
#include "zlib.h"