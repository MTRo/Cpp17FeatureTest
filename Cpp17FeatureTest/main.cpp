
#include <experimental/resumable>
#include <future>
#include <chrono>
#include <iostream>

std::future<bool> DoWork()
{
	printf("Task creating.\n");

	auto task = std::async([] {
		printf("Doing something.\n");

		//Do heavy load here.
		std::this_thread::sleep_for(std::chrono::seconds(1)); // 1秒

		printf("Finish something.\n");
		return true;
	});

	printf("Task created.\n");

	return task;
}


std::future<int> WorkWorkWatching()
{
	printf("Start.\n");

	auto task_result = __await DoWork();

	printf("Done.\n");

	return task_result ? 1 : 0;
}

int main()
{
	auto res = WorkWorkWatching().get();
	printf("Result=%d \n", res);

	system("pause");
}
