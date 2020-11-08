#include <debugger.h>
#include <entity.h>
#include <sim.h>
#include <stdio.h>

#include <mutex>
#include <thread>

std::mutex mtx;

sim s;
int wins;
std::vector<entity> entityList;
std::vector<std::thread> simThreads;
