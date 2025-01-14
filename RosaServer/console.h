#pragma once

#include <csignal>
#include <mutex>
#include <queue>
#include <string>

namespace Console {
extern std::queue<std::string> commandQueue;
extern std::mutex commandQueueMutex;
extern std::mutex autoCompleteMutex;
extern std::sig_atomic_t shouldExit;

bool isAwaitingAutoComplete();
std::string getAutoCompleteInput();
void respondToAutoComplete(std::string_view newBuffer);
void pushCommand(const std::string& input);
void threadMain();
void init();
void cleanup();
void log(std::string_view line);
void handleInterruptSignal(int signal);
void setTitle(const char* title);
}  // namespace Console