#pragma once
#include "sol.hpp"

#include <string>
#include <sys/resource.h>

class ChildProcess
{
	int fdParentToChild[2];
	int fdChildToParent[2];
	int pid;

	bool gotExitCode = false;
	int exitCode;

	void setLimit(__rlimit_resource resource, rlim_t softLimit, rlim_t hardLimit);
public:
	ChildProcess(std::string fileName);
	~ChildProcess();
	bool isRunning();
	void terminate();
	sol::object getExitCode(sol::this_state s);
	sol::object receiveMessage(sol::this_state s);
	void sendMessage(std::string message);
	void setCPULimit(rlim_t softLimit, rlim_t hardLimit);
	void setMemoryLimit(rlim_t softLimit, rlim_t hardLimit);
	void setFileSizeLimit(rlim_t softLimit, rlim_t hardLimit);
};