#include "Utils/TThreadSafeQueue.h"

template <typename T>
void TThreadSafeQueue<T>::Push(T NewValue)
{
	std::lock_guard Lock(M);
	Q.push(NewValue);
	DataCond.notify_one(); // 通知等待的线程
}

template <typename T>
T TThreadSafeQueue<T>::WaitAndPop(T& Value)
{
	std::unique_lock Lock(M);
	DataCond.wait(Lock, [&] { return !Q.empty(); }); // 等待直到队列非空
	Value = Q.front();
	return Q.pop();
}

template <typename T>
bool TThreadSafeQueue<T>::TryPop(T& Value)
{
	std::lock_guard Lock(M);
	if (Q.empty()) return false;
	Value = Q.front();
	Q.pop();
	return true;
}

template <typename T>
bool TThreadSafeQueue<T>::Empty() const
{
	std::lock_guard Lock(M);
	return Q.empty();
}
