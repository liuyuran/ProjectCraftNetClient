#pragma once

#include "CoreMinimal.h"

#include <queue>
#include <mutex>
#include <condition_variable>
 
template<typename T>
class TThreadSafeQueue {
	std::queue<T> Q;
	mutable std::mutex M;
	std::condition_variable DataCond;
 
public:
	TThreadSafeQueue() {}
 
	void Push(T New_Value);
 
	T WaitAndPop(T& Value);
 
	bool TryPop(T& Value);
 
	bool Empty() const;
};
